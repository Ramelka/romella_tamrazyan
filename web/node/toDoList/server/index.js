const fs = require('fs');
const express = require("express");
const cors = require('cors');

const todos = require('./toDo.json');
const users = require('./users.json');

const PORT = 3001;
const app = express();
app.use(express.json());
app.use(cors());

app.get('/users', (req, res) => {
  res.json(users);
});

app.get('/users/:id', (req, res) => {
  const userTodos = todos.filter(todo => todo.userId === Number(req.params.id));
  res.json(userTodos);
});

app.post('/users/:id/addToDo', (req, res) => {
  const data = fs.readFileSync('toDo.json',{'encoding':'utf8'})
  const json = JSON.parse(data);
  const todo = {
    id:Date.now(),
    task:  req.body.newToDo,
    userId: Number(req.params.id),
    isCompleted: false
  };
  fs.writeFileSync('toDo.json', JSON.stringify([...json, todo], undefined, 2));
  return res.json(todo);
})

app.post('/users/:id/update', (req, res) => {
  const id = Number(req.params.id);
  fs.readFile('toDo.json', function (err, data) {
    let json = JSON.parse(data)
    json = json.map((todo) => {
      if (todo.id === id) {
        todo.isCompleted = !todo.isCompleted;
      }
      return todo;
    });

    fs.writeFile('toDo.json', JSON.stringify(json,undefined,2), function() {});
  });
  res.end();
});

app.post('/users/:id/deleteToDo',(req,res) => {
  const id = Number(req.params.id);
  fs.readFile('toDo.json', function (err, data) {
    let json = JSON.parse(data);
    json = json.filter((todo) => {
      if(todo.userId === id && todo.isCompleted === true){
        return false;
      }
      return true;
    });
    fs.writeFile('toDo.json',JSON.stringify(json,undefined,2),function() {});
  });
  res.end();
});

app.listen(PORT);