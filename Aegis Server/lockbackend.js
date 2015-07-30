
var connect = function(command){
  var s = require('net').Socket();
  s.connect(3490, 'localhost');
  s.write(command);

  s.on('data', function(d){
      console.log(d.toString());
    });

  s.end();
}

connect('O');
