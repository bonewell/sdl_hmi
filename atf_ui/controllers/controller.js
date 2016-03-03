var express = require('express');
var child_process = require('child_process');
var fs = require("fs");
var WebSocketServer = require('ws');
var psTree = require('ps-tree');
var model = require('../model/model.js');

var controller = {
    atf_process: null,
    sdl_process: null,
    atf_path: __dirname + "/../../atf_bin/",
    log_error: "ERROR: ",
    log_warn: "WARNING: ",
    log_debug: "DEBUG: "
};

var uploadPath = '/tmp/uploads/';
var testSuitePath = '/tmp/testsuits/';

controller.init = function(){

    try {
        fs.mkdirSync(testSuitePath);
    } catch(e) {
        if ( e.code != 'EEXIST' ) throw e;
    }
    try {
        fs.mkdirSync(uploadPath);
    } catch(e) {
        if ( e.code != 'EEXIST' ) throw e;
    }
    try {
        fs.mkdirSync(controller.atf_path + "files/");
    } catch(e) {
        if ( e.code != 'EEXIST' ) throw e;
    }


// подключенные клиенты
    controller.clients = {};
    controller.clients[0] = {};

// WebSocket-сервер на порту 8081
    var SDLLogServer = new WebSocketServer.Server({
        port: 8081
    });
    var ATFLogServer = new WebSocketServer.Server({
        port: 8082
    });

    SDLLogServer.on('connection', function(ws) {

        console.log(controller.clients);
        controller.clients[0].sdl = ws;
        console.log("----------SDLLogServer New connection established.");

        ws.on('message', function(message) {
            console.log('----------SDLLogServer Got message:  ' + message);

            controller.clients[0].sdl.send(message);
        });

        ws.on('close', function() {
            console.log('----------SDLLogServer Connection closed.');
            delete controller.clients[0];
        });

    });

    ATFLogServer.on('connection', function(ws) {

        controller.clients[0].atf = ws;
        console.log("----------ATFLogServer New connection established.");

        ws.on('message', function(message) {
            console.log('----------ATFLogServer Got message:  ' + message);

            controller.clients[0].atf.send(message);
        });

        ws.on('close', function() {
            console.log('----------ATFLogServer Connection closed.');
            delete controller.clients[0];
        });

    });
};

controller.copyAdditionalFiles = function() {
    fs.readdir(uploadPath, function(err, files) {
        if(err) {
            console.log(controller.log_error +
            "failed to read uploaded files directory. " + err);
            return;
        }
        console.log(files);
        files = files.filter(function(file) {
            return !(file === '.' || file === '..'
            || require("path").extname(file) === '.lua');
        });
        console.log(files);
        files.forEach(function(file) {
            require('child_process').spawn('mv', [uploadPath + file, controller.atf_path + "files/"]);
        });
    });
};

controller.newUser = function(req, res) {
    switch (req.body.objectData) {
        case 'login' :
        {
            console.log('----------Received request login................');
            console.log('----------User Name is................' + req.body.data);
            console.log('----------MainConfig is................');
            console.log(req.app.locals.mainConfig);

            req.session.userName = req.body.data;

            if (req.app.locals.mainConfig === null) {
                req.app.locals.mainConfig = {};
                req.app.locals.mainConfig[req.body.data] = {};
            }

            console.log('----------MainConfig is................');
            console.log(req.app.locals.mainConfig);

            res.status(201).send('new user');
            break;
        }
        default:
        {
            console.log('----------Undefined route: ' + req.body.objectData);
            res.status(404).end();
        }
    }
};

controller.register = function(req, res){
    console.log('----------Register GET controller with data: ', req.body);

    console.log(req.session);

    var db = req.db;
    var users = [];

    var collection = db.collection("users");

    // Fetch the users list
    collection.find({userName: "defaultUser"}).toArray(function(err, docs) {
        if (err) {
            console.log("ERR----------Can not find default user config! ", err);
        } else {

            res.locals.session.user = docs[0];
            res.render('config', {status: "register", session: res.locals.session.user, configIndex: 0});
        }
    });

};

controller.addConfig = function (req, res) {
    console.log(req.session)
    res.locals.session.user.config.push(model.defaultConfig);
    res.redirect("back");
};

controller.login = function(req, res){
    console.log('----------Login POST controller with data: ', req.body);
    req.db.get('usercollection').find(
        {
            "userName":req.body.userName,
            "password":req.body.password
        },
        {},
        function(e, docs){
            if (docs.length === 1) {
                req.session.user = docs[0];
                res.redirect("back");
            }
        }
    );
};

/**
 * Method to save configuration data from config.jade view
 * to /tmp/config.json
 * @param req
 * @param res
 */
controller.saveConfiguration = function(req, res) {

    console.log("----------Save Configuration enter...................");

    console.log("----------User Name " + req.body.userName);

    //req.db.collection("users").find({userName: req.body.userName}).toArray(function(err, docs){
    //    if (err) {
    //        console.log("ERR----------Can not make request to database", err);
    //    } else if (docs.length == 0) {
    //
    //    }
    //});

    req.db.collection("users").insert({
        userName: req.body.userName,
        userEmail: req.body.email,
        userPassword: req.body.password,
        config:[{
            file_path: req.body.file_path,
            hb_timeout: req.body.hb_timeout,
            testRecord_path: req.body.testRecord_path,
            MOB_connection_str: req.body.MOB_connection_str,
            HMI_connection_str: req.body.HMI_connection_str,
            PerfLog_connection_str: req.body.PerfLog_connection_str,
            client_PerfLog_connection_str: req.body.client_PerfLog_connection_str,
            launch_time: req.body.launch_time,
            terminal_name: req.body.terminal_name,
            SDLStoragePath: req.body.SDLStoragePath
        }]
    }, function(err, docs){
        console.log(err, docs);
    });

    res.redirect("back");
};

/**
 * Method to load configuration view test_suite.jade
 *
 * @param req
 * @param res
 */
controller.testSuiteRun = function(req, res) {

    res.render('test_suite', {
        title: 'Test suite',
        config: req.app.locals.mainConfig[req.session.userName]
    });
};

function logAndSendError(response, log_string, error) {
    console.log(log_string + error);
    //response.status(500).end();
}

function killTreeProcesses (pid, signal, callback) {
    signal   = signal || 'SIGHUP';
    callback = callback || function () {};
    psTree(pid, function (err, children) {
        [pid].concat(
            children.map(function (p) {
                return p.PID;
            })
        ).forEach(function (tpid) {
            try { process.kill(tpid, signal) }
            catch (ex) { }
        });
        callback();
    });
};


/**
 * UI AJAX post requests handler
 * @param req
 * @param res
 */
controller.test_suite_config = function(req, res) {
    var fs = require("fs");
    var results = [];
    var path = '';
    var list;
    var filePath;
    var currentTestSuite;

    console.log(req.body.objectData, "request received................");

    switch (req.body.objectData) {
        case 'test_cases_list' : {
            console.log('----------Received request test_cases_list................');

            results = [];
            list = fs.readdirSync(uploadPath);
            list.forEach(function(file) {
                filePath = uploadPath + file;
                var stat = fs.statSync(filePath);
                if (!(stat && stat.isDirectory()) && require('path').extname(file) === '.lua') {
                    results.push(file);
                }
            });

            res.status(201).send(results);
            break;
        }
        case 'test_suite_list' : {
            console.log('----------Received request test_suits_list................');

            results = [];
            list = fs.readdirSync(testSuitePath);
            list.forEach(function(file) {
                filePath = testSuitePath + file;
                var stat = fs.statSync(filePath);
                if (stat && stat.isDirectory()) {
                    results.push(file);
                }
            });

            res.status(201).send(results);
            break;
        }
        case 'test_suite_description' : {
            console.log('----------Received request test_suite_description................');

            if(req.body.data){
                currentTestSuite = req.body.data;
            } else {
                list = fs.readdirSync(testSuitePath);
                currentTestSuite = list[0];
            }

            path = testSuitePath + currentTestSuite;
            list = fs.readdirSync(path);
            results = [];

            results.push("Test suite " + req.body.data);

            list.forEach(function(file) {
                filePath = path + "/" + file;
                console.log(filePath);
                var stat = fs.statSync(filePath);
                if (!(stat && stat.isDirectory())) {
                    results.push(file);
                }
            });

            res.status(201).send(results);
            break;
        }
        case 'start_atf' : {
            console.log('----------Received request to run ATF for testsuits: ' + req.body.data.test_suits);
            this.copyAdditionalFiles();

            var test_suits = req.body.data.test_suits;

            console.log(req.app.locals.mainConfig[req.session.userName]);

            if (!req.app.locals.mainConfig[req.session.userName].file_path) {
                logAndSendError(res, "Path to SDL is not set");
                break;
            }
            if (!this.sdl_process) {
                console.log("----------Start SDL.............");

                var proc = child_process.exec;

                this.sdl_process = proc(req.app.locals.mainConfig[req.session.userName].file_path,
                    {'cwd': require('path').dirname(req.app.locals.mainConfig[req.session.userName].file_path)});

                this.sdl_process.stdout.on('data', function (data) {
                    controller.clients[0].sdl.send(data);
                });

                this.sdl_process.stderr.on('data', function (data) {
                    controller.clients[0].sdl.send(data);
                });

                this.sdl_process.on('exit', function (code) {
                    controller.clients[0].sdl.send(code);
                });
            }

            // Silent needed to handle logs from child process
            this.atf_process = child_process.fork(
                __dirname + '/run_atf.js',
                [test_suits, testSuitePath],
                {
                    silent:true
                }
            );

            this.atf_process.on('message', function(m) {
                controller.clients[0].atf.send('' + m);
            });

            this.atf_process.stdout.on('data', function (data) {
                controller.clients[0].atf.send('' + data);
            });

            this.atf_process.stderr.on('data', function (data) {
                controller.clients[0].atf.send('' + data);
            });

            this.atf_process.on('exit', function (code) {
                controller.clients[0].atf.send('child process exited with code ' + code);
            });

            this.atf_process.on('close', function (code) {
                controller.clients[0].atf.send('child process exited with code ' + code);
                controller.atf_process = null;
            });

            res.status(201).send("Done");

            break;
        }
        case 'stop_atf' : {
            if (this.atf_process) {
                killTreeProcesses(this.atf_process.pid, 'SIGHUP', function(){
                    controller.atf_process = null;
                    res.status(201).send();
                });
            }
            break;
        }
        case 'stop_sdl' : {
            if (this.sdl_process && !this.atf_process) {
                killTreeProcesses(this.sdl_process.pid, 'SIGHUP', function(){
                    controller.sdl_process = null;
                    res.status(201).send();
                });
            }
            break;
        }
        case 'add_test_suit' : {
            console.log('----------Received request to add new test suit with scripts: ' + req.body.data.test_scripts);
            path = "/tmp/testsuits/" + req.body.data.folder_name + "/";
            console.log('----------path ' + path);
            fs.mkdirSync(path, function(err) {
                    if (err && err.code != 'EEXIST') {
                        logAndSendError(res, 'Failed to create/read test suit directory ' + req.body.data.folder_name, err);
                        res.status(201).send();
                        return;
                    }});

            for(var i = 0; i < req.body.data.test_scripts.length; i++){

                require('child_process').spawn('mv', [uploadPath + req.body.data.test_scripts[i], path]);

            }
            break;
        }
        default: {
            console.log('----------Undefined route: ' + req.body.objectData);
            res.status(404).end();
        }
    }
};

module.exports = controller;