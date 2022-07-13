// Server returning html
const http = require('http');
const fs = require('fs');
const host = 'localhost';
const port = 3000;

const server = http.createServer((request, response) => {
    response.writeHead(200, { 'Content-Type': 'text/html' });
    fs.readFile('../index.html', ((error, data) => {
        if (error) {
            response.writeHead(404);
            response.write('No such file');
        } else {
            response.write(data);
        }
        response.end();
    }));
});

server.listen(port, host, () => {
    console.log(`Server is running on http://${host}:${port}`);
});