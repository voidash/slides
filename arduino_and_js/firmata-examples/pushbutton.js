var five = require("johnny-five");
var board = new five.Board();

board.on("ready", function() {
    const led = new five.Led(7);
    const pushButton = new five.Button(
        {
            pin: 8,
            isPullup : true
        }
    );
    pushButton.on('down', () => {

        if (!led.isOn) {led.on();} else {led.off()}
    });

});