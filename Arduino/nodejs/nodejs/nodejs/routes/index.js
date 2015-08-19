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


var SerialPort = require("serialport").SerialPort

// Arduino가 /dev/tty-usbserial1 에 연결되었다고 가정합니다.
var serialPort = new SerialPort("/dev/tty.usbmodem1421", {
    baudrate: 9600
}, false);

serialPort.open(function () {
    console.log('접속되었구요');
    serialPort.on('data', function(data) {
        // Arduino 쪽에서 뭔가 출력했다면 여길 통해서 데이터를 볼 수 있습니다.
        console.log('data received: ' + data);
    });
    
    setInterval(function(){
        console.log('sending: '+ ledStatus);
        serialPort.write(ledStatus ? "1" : "0", function(err, results) {
            // LED가 ON/OFF 될꺼에요
        });     
    }, 1000);
});

module.exports = router;
