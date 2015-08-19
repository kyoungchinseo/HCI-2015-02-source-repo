var express = require('express');
var router = express.Router();

var ledStatus = false;


/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'NodeJs + Arduino' });
});

router.post('/', function(req, res) {
  ledStatus = ledStatus ? false : true;
  console.log(ledStatus);
  res.render('index', {title: 'NodeJs + Arduino'});
});

var five = require('johnny-five');
var board = new five.Board();

board.on("ready", function() {
  this.pinMode(13,1);

  this.loop(100, function() {
    this.digitalWrite(13, ledStatus? 1: 0);
  });
});


module.exports = router;
