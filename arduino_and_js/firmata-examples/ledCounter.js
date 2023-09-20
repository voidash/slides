const five = require("johnny-five");
const board = new five.Board();


board.on("ready", () => {
    let leds = [8,9,10,11,12].map((pinNo) => {
       return new five.Led(pinNo);
    });

    for (let i = 0 ; i <= 31; i++) {
        setTimeout(() => {ledState(i.toString(2).padStart(5,'0') ,leds)},i * 1000);
    }


}) ;

function ledState(ledString,leds) {
    Array.from("00000").map((val,index) => setLedState(leds[index], parseInt(val)));
    Array.from(ledString).map((val,index) => setLedState(leds[index], parseInt(val)));
}

function setLedState(led, state) {
    state == 1 ? led.on() : led.off();
}