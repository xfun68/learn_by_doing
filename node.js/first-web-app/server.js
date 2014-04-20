var http = require('http');

function start() {
  var onRequest = function(request, response) {
    console.log('Request received');
    response.writeHead(200, {'Content-Tpye': 'text/plain'});
    response.write('Hello World');
    response.end();
  }

  http.createServer(onRequest).listen(8888);

  console.log('Server has started.');
}

exports.start = start;

