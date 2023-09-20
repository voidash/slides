var five = require("johnny-five");

board = new five.Board();

board.on("ready", function() {

    let photoresistor = new five.Sensor({
        pin: "A0",
        freq: 500
    });

    let led = new five.Led(8);

    // board.repl.inject({
    //     pot: photoresistor
    // });

    photoresistor.on("data", function() {
        console.log(this.value);
        if (this.value >= 1000) {
            led.on();
        }else {
            led.off();
        }
    });
});


