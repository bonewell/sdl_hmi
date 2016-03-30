var express = require('express');
var router = express.Router();
var controller = require('../controllers/controller.js');

function isAuthenticated(req, res, next) {

    if (req.session.user) {
        console.log("----------USER AUTHORISED!");
        return next();
    }

    // IF A USER ISN'T LOGGED IN, THEN REDIRECT THEM TO HOME PAGE

    console.log("ERR----------USER AUTHORISED!");
    req.session.errMSG = "Please Log in immediately :(";
    res.redirect('/');
}

/* GET home page. */
router.get('/', function(req, res, next) {

    var db = req.db;
    var users = [];

    var collection = db.collection("users");

    var error = req.session.errMSG;

    req.session.errMSG = null;

    // Fetch the users names list
    collection.find({}, { "userName": 1, _id: 0 }).toArray(function(err, docs) {
        req.session.errMSG = null;
        res.render('index', { users: docs, errorMessage: error });
    });
});

/* GET main configuration page. */
router.get('/config', isAuthenticated, function(req, res, next) {
    console.log("----------Config GET enter...................");
    controller.config(req, res);
});

/* GET test suite configuration page. */
router.get('/test_suite', isAuthenticated, function(req, res, next) {
    console.log("----------test_suite GET enter...................");

    controller.testSuite(req, res);
});

/* GET test suite configuration page. */
router.post('/addTestSuit', isAuthenticated, function(req, res, next) {
    console.log("----------addTestSuit GET enter...................");

    controller.addTestSuit(req, res);
});

/* GET test suite configuration page. */
router.post('/editTestSuit', isAuthenticated, function(req, res, next) {
    console.log("----------editTestSuit GET enter...................");

    controller.editTestSuit(req, res);
});

/* GET test suite configuration page. for post ajax requests from UI*/
router.post('/test_suite_config', isAuthenticated, function(req, res, next) {
    controller.test_suite_config(req, res);
});

/* POST main configuration page form submit handler. */
router.post('/save', function(req, res, next) {
    console.log("----------Save Configuration POST enter...................");

    controller.saveConfiguration(req, res);
});

/* POST main configuration page form submit handler. */
router.post('/login', function(req, res, next) {

    console.log("----------Login POST enter...................");
    controller.login(req, res);
});

/* POST main configuration page form submit handler. */
router.get('/logOut', isAuthenticated, function(req, res, next) {

    console.log("----------logOut POST enter...................");
    req.session.user = null;
    res.redirect("/");
});

/* POST main configuration page form submit handler. */
router.post('/ajax', isAuthenticated, function(req, res, next) {

    console.log("----------AJAX POST enter...................");
    controller.ajax(req, res);
});

/* GET main configuration page form submit handler. */
router.get('/selectConfig/:index', isAuthenticated, function(req, res, next) {

    console.log("----------selectConfig GET enter...................");
    controller.selectConfig(req, res);
});

/* POST main configuration page form submit handler. */
router.get('/register', function(req, res, next) {

    console.log("----------Register GET enter...................");
    controller.register(req, res);
});

/* POST main configuration page form submit handler. */
router.get('/addConfig', isAuthenticated, function(req, res, next) {

    console.log("----------addConfig GET enter...................");
    controller.addConfig(req, res);
});

/* POST main configuration page form submit handler. */
router.post('/upload', isAuthenticated, function(req, res, next) {
        console.log('----------TRYING TO UPLOAD................');
        controller.upload(req, res);
});

/* GET main configuration page. */
router.get('/userlist', isAuthenticated, function(req, res) {
    var db = req.db;
    var collection = db.get('usercollection');
    collection.find({},{},function(e,docs){
       res.render('userlist', {
          "userlist": docs
       });
    });
});

module.exports = router;