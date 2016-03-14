var express = require('express');

var model = {};
var MongoClient = require('mongodb').MongoClient;


/**
 * Default user configuration params
 * You must change data here and delete database to new params take effect
 * */
model.defaultConfig = {
    index: 0,
    file_path: 'default',
    hb_timeout: 'default',
    testRecord_path: 'default',
    MOB_connection_str: 'default',
    HMI_connection_str: 'default',
    PerfLog_connection_str: 'default',
    client_PerfLog_connection_str: 'default',
    launch_time: 'default',
    terminal_name: 'default',
    SDLStoragePath: 'default'
};

model.init = function(main_db){

    console.log("----------MODEL INIT FUNCTION!");

    // Connect to the db
    MongoClient.connect("mongodb://localhost:27017/ATF", function(err, db) {
        if (!err) {
            console.log("----------We are connected to ATF DataBase!");
        } else {
            return console.dir(err);
        }

        db.command({listCollections: 1}, function (err, cb) {
            if (!err) {
                if (cb.cursor.firstBatch.length == 0) {

                    console.log("----------DataBase is empty! Trying to create default user.");

                    db.createCollection('users', function (err, collection) {

                        if (err) {
                            return console.log("ERR----------Can not create collection: ", err);
                        }

                        console.log("----------Users collection created successfuly! Trying to add default user");

                        collection.insert({
                            userName: "defaultUser",
                            userEmail: "default@mail.com",
                            userPassword: "default",
                            config: [model.defaultConfig]
                        }, function (err, doc) {
                            if (err) {
                                console.log("ERR----------Can not insert default user", err);
                            } else {
                                console.log("----------User added fuccessfuly", doc);

                                main_db.open(function(err, db) {
                                    if (err) {
                                        console.log("ERR----------Can not open DB", err);
                                    } else {
                                        console.log("----------ATF DataBase connection established! ");
                                    }
                                });
                            }
                        })
                    });
                } else {
                    main_db.open(function(err, db) {
                        if (err) {
                            console.log("ERR----------Can not open DB", err);
                        } else {
                            console.log("----------ATF DataBase connection established! ");
                        }
                    });
                }
            }
        });
    });

};

module.exports = model;
