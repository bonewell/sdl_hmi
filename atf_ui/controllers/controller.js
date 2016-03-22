var express = require('express');
var child_process = require('child_process');
const fs = require("fs");
var path = require('path');
var WebSocketServer = require('ws');
var psTree = require('ps-tree');
var model = require('../model/model.js');
var multer  = require('multer');


var controller = {
    atf_process: null,
    sdl_process: null,
    atf_path: __dirname + "/../../atf_bin/",
    log_error: "ERROR: ",
    log_warn: "WARNING: ",
    log_debug: "DEBUG: ",
    configIndex: 0,
    ATFVersions: [
        {
            id: 0,
            name: "2.2",
            link: ""
        },
        {
            id: 1,
            name: "2.1",
            link: ""
        }
    ]
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

controller.upload = function(req, res){

    var oldFile;
    var newFile;
    var newPath;

    for ( var file in req.files) {

        newPath = testSuitePath.concat( req.session.user.userName.concat( '/' + req.body.testSuiteName + '/' ) );

        console.log(newPath);

        oldFile = fs.createReadStream(file.path);
        newFile = fs.createWriteStream(newPath);
        oldFile.on('end', function () {
            console.log('----------Added ');
        });

        oldFile.pipe(newFile);
    }

    res.redirect("back");
};

controller.config = function(req, res){
    console.log('----------Config CONTROLLER with data: ', req.body);

    if (req.session.user.userName) {
        res.render('config', {status: "edit", session: req.session, configIndex: controller.configIndex});
    } else {
        res.redirect("back");
    }
};

controller.selectConfig = function(req, res){
    console.log('----------selectConfig CONTROLLER with data: ', req.params);

    if (req.session.user.config.length >= req.params.index && req.params.index >= 0) {
        controller.configIndex = req.params.index;
    }
    res.redirect("back");
};

controller.register = function(req, res){
    console.log('----------Register CONTROLLER with data: ', req.body);

    var db = req.db;
    var users = [];

    var collection = db.collection("users");

    // Fetch the users list
    collection.find({userName: "defaultUser"}).toArray(function(err, docs) {
        if (err) {
            console.log("ERR----------Can not find default user config! ", err);
        } else {

            res.render('config', {status: "register", session: {user: docs[0]}, configIndex: 0});
        }
    });

};

controller.addConfig = function (req, res) {

    console.log('----------addConfig CONTROLLER with data: ', req.body);

    var index = res.locals.session.user.config.length;

    res.locals.session.user.config.push(model.defaultConfig);

    res.locals.session.user.config[index].index = index;

    console.log(res.locals.session.user);

    req.db.collection("users").update({userName: res.locals.session.user.userName}, {$set: {config: res.locals.session.user.config}}, function(err, docs){

        if (!err) {

            console.log('----------Configuration added successfully');
            res.redirect("back");
        } else {

            console.log("ERR----------Configuration add error ", err);
            res.redirect("back");
        }
    });
};

/**
 * AJAX requests handler
 * @param req
 * @param res
 */
controller.ajax = function(req, res){
    console.log('----------ajax CONTROLLER with data: ', req.body);

    var results = [];
    var path = '';
    var list;
    var filePath;
    var currentTestSuite;

    switch (req.body.objectData) {
        case "isUserExist": {

            req.db.collection("users").find({userName: req.body.data}).toArray(function(err, docs){
                if (err) {
                    res.status(404).send("Data base internal error;", err);
                } else {
                    if (docs.length > 0) {
                        res.status(500).send("User name already registered! Please try again ;)");
                    } else {
                        res.status(200).send("Correct name ;)");
                    }
                }
            });
            break;
        }
        //case 'test_cases_list' : {
        //    console.log('----------Received request test_cases_list................');
        //
        //    results = [];
        //    list = fs.readdirSync(uploadPath);
        //    list.forEach(function(file) {
        //        filePath = uploadPath + file;
        //        var stat = fs.statSync(filePath);
        //        if (!(stat && stat.isDirectory()) && require('path').extname(file) === '.lua') {
        //            results.push(file);
        //        }
        //    });
        //
        //    res.status(201).send(results);
        //    break;
        //}
        //case 'test_suite_list' : {
        //    console.log('----------Received request test_suits_list................');
        //
        //    results = [];
        //    list = fs.readdirSync(testSuitePath);
        //    list.forEach(function(file) {
        //        filePath = testSuitePath + file;
        //        var stat = fs.statSync(filePath);
        //        if (stat && stat.isDirectory()) {
        //            results.push(file);
        //        }
        //    });
        //
        //    res.status(201).send(results);
        //    break;
        //}
        //case 'test_suite_description' : {
        //    console.log('----------Received request test_suite_description................');
        //
        //    if(req.body.data){
        //        currentTestSuite = req.body.data;
        //    } else {
        //        list = fs.readdirSync(testSuitePath);
        //        currentTestSuite = list[0];
        //    }
        //
        //    path = testSuitePath + currentTestSuite;
        //    list = fs.readdirSync(path);
        //    results = [];
        //
        //    results.push("Test suite " + req.body.data);
        //
        //    list.forEach(function(file) {
        //        filePath = path + "/" + file;
        //        console.log(filePath);
        //        var stat = fs.statSync(filePath);
        //        if (!(stat && stat.isDirectory())) {
        //            results.push(file);
        //        }
        //    });
        //
        //    res.status(201).send(results);
        //    break;
        //}
        //case 'start_atf' : {
        //    console.log('----------Received request to run ATF for testsuits: ' + req.body.data.test_suits);
        //    this.copyAdditionalFiles();
        //
        //    var test_suits = req.body.data.test_suits;
        //
        //    console.log(req.app.locals.mainConfig[req.session.userName]);
        //
        //    if (!req.app.locals.mainConfig[req.session.userName].file_path) {
        //        logAndSendError(res, "Path to SDL is not set");
        //        break;
        //    }
        //    if (!this.sdl_process) {
        //        console.log("----------Start SDL.............");
        //
        //        var proc = child_process.exec;
        //
        //        this.sdl_process = proc(req.app.locals.mainConfig[req.session.userName].file_path,
        //            {'cwd': require('path').dirname(req.app.locals.mainConfig[req.session.userName].file_path)});
        //
        //        this.sdl_process.stdout.on('data', function (data) {
        //            controller.clients[0].sdl.send(data);
        //        });
        //
        //        this.sdl_process.stderr.on('data', function (data) {
        //            controller.clients[0].sdl.send(data);
        //        });
        //
        //        this.sdl_process.on('exit', function (code) {
        //            controller.clients[0].sdl.send(code);
        //        });
        //    }
        //
        //    // Silent needed to handle logs from child process
        //    this.atf_process = child_process.fork(
        //        __dirname + '/run_atf.js',
        //        [test_suits, testSuitePath],
        //        {
        //            silent:true
        //        }
        //    );
        //
        //    this.atf_process.on('message', function(m) {
        //        controller.clients[0].atf.send('' + m);
        //    });
        //
        //    this.atf_process.stdout.on('data', function (data) {
        //        controller.clients[0].atf.send('' + data);
        //    });
        //
        //    this.atf_process.stderr.on('data', function (data) {
        //        controller.clients[0].atf.send('' + data);
        //    });
        //
        //    this.atf_process.on('exit', function (code) {
        //        controller.clients[0].atf.send('child process exited with code ' + code);
        //    });
        //
        //    this.atf_process.on('close', function (code) {
        //        controller.clients[0].atf.send('child process exited with code ' + code);
        //        controller.atf_process = null;
        //    });
        //
        //    res.status(201).send("Done");
        //
        //    break;
        //}
        //case 'stop_atf' : {
        //    if (this.atf_process) {
        //        killTreeProcesses(this.atf_process.pid, 'SIGHUP', function(){
        //            controller.atf_process = null;
        //            res.status(201).send();
        //        });
        //    }
        //    break;
        //}
        //case 'stop_sdl' : {
        //    if (this.sdl_process && !this.atf_process) {
        //        killTreeProcesses(this.sdl_process.pid, 'SIGHUP', function(){
        //            controller.sdl_process = null;
        //            res.status(201).send();
        //        });
        //    }
        //    break;
        //}
        default: {
            console.log('----------Undefined route: ' + req.body.objectData);
            res.status(404).end();
        }
    }
};

controller.login = function(req, res){
    console.log('----------Login CONTROLLER with data: ', req.body);
    req.db.collection("users").find(
        {
            "userName":req.body.userName,
            "userPassword":req.body.password
        }
    ).toArray(function(err, docs){
        if (docs.length === 1) {
            controller.configIndex = 0;
            req.session.user = docs[0];
            res.redirect("back");
        } else {
            req.session.errMSG = "User password incorrect! :(";
            res.redirect("back");
        }
    });
};

controller.copyDir = function(src, dest) {
    fs.mkdirSync(dest);
    var files = fs.readdirSync(src);
    for(var i = 0; i < files.length; i++) {
        var current = fs.lstatSync(path.join(src, files[i]));
        if(current.isDirectory()) {
            controller.copyDir(path.join(src, files[i]), path.join(dest, files[i]));
        } else if(current.isSymbolicLink()) {
            var symlink = fs.readlinkSync(path.join(src, files[i]));
            fs.symlinkSync(symlink, path.join(dest, files[i]));
        } else {
            controller.copy(path.join(src, files[i]), path.join(dest, files[i]));
        }
    }
};

controller.copy = function(src, dest) {
    var oldFile = fs.createReadStream(src);
    var newFile = fs.createWriteStream(dest);
    oldFile.on('data', function(chunk) {
        console.log('got %d bytes of data', chunk.length);
    });

    oldFile.pipe(newFile);
};

/**
 * Method to save configuration data from config.jade view
 * to /tmp/config.json
 * @param req
 * @param res
 */
controller.saveConfiguration = function(req, res) {

    console.log("----------Save Configuration CONTROLLER enter...................");

    var name = req.body.userName ? req.body.userName : req.session.user.userName;

    req.db.collection("users").find({userName: name}).toArray(function(err, docs){

        var newConfig = {
            index: controller.configIndex,
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
        };

        console.log("----------Config to be saved is: ", newConfig);

        if (err) {
            console.log("ERR----------Can not make request to database", err);
            req.session.errMSG = "Can not make request to database: " + err;
            res.redirect("/");
        } else if (docs.length == 0) {

            console.log("----------Start creating new users db record!");

            // if no user found then create new user record
            req.db.collection("users").insert({
                userName: name,
                userEmail: req.body.email,
                userPassword: req.body.password,
                config:[newConfig]
            }, function(err, docs){

                if (!err) {

                    //if user record successfully added to DB then create user folder

                    console.log("----------Start creating new users folder!");

                    fs.mkdir(testSuitePath.concat(name), function(err) {
                        if (err) {
                            console.log("ERR----------Error with creation users folder: ", err);

                            req.session.errMSG = "Error with creation users folder: " + err;
                            res.redirect("/");
                        } else {
                            console.log("----------Created new user folder successfully");

                            console.log("----------Start configure user data");

                            controller.copyDir(controller.atf_path, testSuitePath.concat( name.concat( '/atf' ) ) );

                            console.log("----------Finished configure user data");

                            res.redirect("/");
                        }
                    });
                } else {
                    console.log("ERR----------Error with creation users record in db: ", err);
                    req.session.errMSG = "Error with creation users record in db: " + err;
                    res.redirect("/");
                }
            });

        } else {
            console.log("----------Trying update user : config " + controller.configIndex);

            //if user is registered then update user config data
            req.db.collection("users").update({
                userName: name,
                config: {
                    // find needed array item in array of configs
                    $elemMatch: {
                        "index" : parseInt(controller.configIndex)
                    }
                }
            },{
                //update only one array in collection item
                $set:{
                    'config.$':newConfig
                }
            }, function(err, docs){

                if (!err) {
                    console.log("----------Update existing user complete");
                    res.locals.session.user.config[controller.configIndex] = newConfig;

                    res.redirect("/config");
                }
            });
        }
    });
};

/**
 * Method to load configuration view test_suite.jade
 *
 * @param req
 * @param res
 */
controller.testSuite = function(req, res) {
    console.log("----------test_suite Controller enter...................");

    req.db.collection("tests").find({userID: req.session.user._id}, { "testSuite": 1, _id: 0 }).toArray(function(err, docs){

        if (err){

            console.log("ERR----------Can not find records in collection tests ", err);
            res.status(500).send(err);
        } else {

            console.log("----------Read records in collection tests successful", docs);
            res.render('test_suite', {configIndex: controller.configIndex, suits: docs});
        }

    });

};

controller.addTestSuit = function(req, res) {
    console.log("----------addTestSuit Controller enter...................");

    console.log('----------Received request to add new test suit: ' + req.body.testSuit);
    path = testSuitePath.concat(req.session.user.userName.concat("/" + req.body.testSuit));
    console.log('----------path ' + path);
    fs.mkdir(path, function(err) {
        if (err) {
            console.log("ERR---------Failed to create/read test suit directory " + path + " with error: ", err);
            //logAndSendError(res, 'Failed to create/read test suit directory ' + req.body.data.folder_name, err);
            res.status(500).send("Could not create directory: ", err);
        } else {
            console.log("---------User test suite directory created successfully");

            req.db.collection("tests").insert({
                testSuite: req.body.testSuit,
                description: "Description",
                userID: req.session.user._id,
                fileName: []
            }, function (err, doc) {
                if (err) {
                    console.log("ERR----------Can not insert test record to collection", err);
                    res.status(500).send(err);
                } else {
                    console.log("----------Test record successfully added to db collection");
                    res.redirect("back");
                }
            });
        }
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

module.exports = controller;
