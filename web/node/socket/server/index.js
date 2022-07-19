const express = require('express');
const http = require('http');
const cors = require('cors');
const { Server } = require('socket.io');

const app = express();
app.use(cors());

const PORT = 3001;
const server = http.createServer(app);

const io = new Server(server, {
    cors: {
        origin: 'http://localhost:3000',
        methods: ['GET', 'POST']
    }
});

io.on('connect', (socket) => {
    console.log(`User ${socket.id} connected`);

    socket.on('joinRoom', (data) => {
        socket.join(data);
    });

    socket.on('sendMessage', (data) => {
        socket.to(data.room).emit('receiveMessage', data);
    });

    socket.on('disconnect', () => {
        console.log(`User ${socket.id} disconnected`)
    });
});

server.listen(PORT);