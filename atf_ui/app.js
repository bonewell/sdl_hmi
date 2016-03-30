var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');
var cookieParser = require('cookie-parser');
var session = require('express-session');
var bodyParser = require('body-parser');
var multer  = require('multer');
var upload = multer({
    dest: '/tmp/uploads/'
});

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

//TO DO uncomment after placing your favicon in /public
//app.use(favicon(__dirname + '/public/favicon.ico'));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(session({secret:'somesecrettokenhere'}));
app.use(express.static(path.join(__dirname, 'public')));

app.use(upload.fields([
    { name: 'lua_upload' },
    { name: 'other_upload' },
    { name: 'modules_upload' }
]));

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
