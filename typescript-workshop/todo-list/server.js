//@ts-check


const {EtherPortClient} = require('etherport-client');

    const express = require('express')
    const app = express()
    const port = 3000

    var state1 = 0;
    var state2 = 0;
    var state3 = 0;
    var state4 = 0;
    var state5 = 0;

    app.listen(port, () => {
      console.log(`Example app listening on port ${port}`)
    })

    const five = require('johnny-five');
    const board = new five.Board({
      port: new EtherPortClient({
        host: '192.168.0.114',
        port: 3030
      }),
      repl: false
    });


    app.get('/light1/:state', (req, res) => {
        state2 = parseInt(req.params.state);
        res.send("ok");
    })

    app.get('/light2/:state', (req, res) => {
        state3 = parseInt(req.params.state);
        res.send("ok");
    })

    app.get('/light3/:state', (req, res) => {
        state4 = parseInt(req.params.state);
        res.send("ok");
    })

    app.get('/light4/:state', (req, res) => {
        state5 = parseInt(req.params.state);
        res.send("ok");
    })
  board.on("ready", function(){
        var led1 = 16;  
        var led2 = 5;
        var led3 = 4 
        var led4 = 0;
        var led5 = 2;
      this.pinMode(led1, this.MODES.OUTPUT);
      this.pinMode(led2, this.MODES.OUTPUT);
      this.pinMode(led3, this.MODES.OUTPUT);
      this.pinMode(led4, this.MODES.OUTPUT);
      this.pinMode(led5, this.MODES.OUTPUT);
      this.loop(100,()=>{
          this.digitalWrite(led1, (state1) );
          this.digitalWrite(led2, (state2) );
          this.digitalWrite(led3, (state3) );
          this.digitalWrite(led4, (state4) );
          this.digitalWrite(led5, (state5) );
      });
  });

