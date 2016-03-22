var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');
var cookieParser = require('cookie-parser');
var session = require('express-session');
var bodyParser = require('body-parser');
//var multer  = require('multer');

// DB mongodb
var Db = require('mongodb').Db;
var Server = require('mongodb').Server;
var db = new Db('ATF', new Server('localhost', 27017), {w:1});

var routes = require('./routes/index');
var users = require('./routes/users');
var controller = require('./controllers/controller.js');
var model = require('./model/model.js');

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');

// uncomment after placing your favicon in /public
//app.use(favicon(__dirname + '/public/favicon.ico'));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(session({secret:'somesecrettokenhere'}));
app.use(express.static(path.join(__dirname, 'public')));


//app.post('/upload',
//    multer({
//    dest: '/tmp/testsuits/',
//    rename: function (fieldname, filename) {
//        return filename; //return name
//    },
//    changeDest: function(dest, req, res) {
//        var newDestination = dest + '123';
//
//        return newDestination
//    }
//}),
//    function(req, res) {
//        console.log(req.body);
//        res.redirect("back");
//});

//app.use(multer({
//    dest: '/tmp/uploads/',
//    //rename to original file name
//    rename: function (fieldname, filename) {
//        return filename; //return name
//    }
//}));

//var storage = multer.diskStorage({
//    destination: '/tmp/testsuits/123/',
//    filename: function (req, file, cb) {
//        cb(null, req.body.file_upload)
//    }
//});

//var upload = multer({ storage: storage });
//
//
//app.post('/upload', upload.single('uploadedFile'), function (req, res, next) {
//    res.end('over');
//});

// Make our db accessible to our router
app.use(function(req,res,next){
    req.db = db;
    res.locals.session = req.session;
    next();
});

app.use('/', routes);
app.use('/users', users);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
    req.db = db;
    var err = new Error('Not Found');
    err.status = 404;
    next(err);
});

// error handlers

// development error handler
// will print stacktrace
if (app.get('env') === 'development') {
  app.use(function(err, req, res, next) {
    res.status(err.status || 500);
    res.render('error', {
      message: err.message,
      error: err
    });
  });
}

// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res, next) {
  res.status(err.status || 500);
  res.render('error', {
    message: err.message,
    error: {}
  });
});

controller.init();
model.init(db);

module.exports = app;
