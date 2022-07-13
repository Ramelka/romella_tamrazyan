// Basic HTTP server
const http = require('http');
const host = 'localhost';
const port = 3000;

const server = http.createServer((request, response) => {
    response.statusCode = 200;
    response.write('Hello everybody!');
    response.end();
});

server.listen(port, host, () => {
    console.log(`Server is running on http://${host}:${port}`);
})