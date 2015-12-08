var express = require('express');
var router = express.Router();
var controller = require('../controllers/controller.js');

/* GET home page. */
router.get('/', function(req, res, next) {

    var db = req.db;
    var collection = db.get('usercollection');
    collection.find({},{},function(e,docs){
        res.render('index', { title: 'ATF', users: docs });
    });
});

/* GET main configuration page. */
router.get('/config', function(req, res, next) {
    res.render('config', { title: 'ATF Configuration' });
});

/* GET test suite configuration page. */
router.get('/test_suite', function(req, res, next) {
    controller.testSuiteRun(req, res);
});

/* GET test suite configuration page. for post ajax requests from UI*/
router.post('/test_suite_config', function(req, res, next) {
    controller.test_suite_config(req, res);
});

/* POST main configuration page form submit handler. */
router.post('/save', function(req, res, next) {

    console.log("----------Save Configuration enter...................");
    controller.saveConfiguration(req, res);
});

/* POST main configuration page form submit handler. */
router.post('/login', function(req, res, next) {

    console.log("----------Login POST enter...................");
    controller.login(req, res);
});

/* POST main configuration page form submit handler. */
router.post('/upload', function(req, res, next) {
    console.log('----------TRYING TO UPLOAD................');
    console.log(req.body);
    console.log(req.files);
    res.redirect("back");
});

/* GET main configuration page. */
router.get('/userlist', function(req, res) {
    var db = req.db;
    var collection = db.get('usercollection');
    collection.find({},{},function(e,docs){
       res.render('userlist', {
          "userlist": docs
       });
    });
});

module.exports = router;