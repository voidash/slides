const five = require("johnny-five");
const board = new five.Board();

board.on("ready", () => {
    const servo = new five.Servo(10);

    board.repl.inject({
        servo
      });
    servo.sweep();
})