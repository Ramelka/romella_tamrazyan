const express = require('express');
const app = express();

app.get('/', (req, res) => {
    res.status(500).json({ message: "Error" });
});

app.get('/users', (req, res) => {
    res.send('Users list');
});

app.get('/users/new', (req, res) => {
    res.send('Users new list');
});

app.listen(3000);