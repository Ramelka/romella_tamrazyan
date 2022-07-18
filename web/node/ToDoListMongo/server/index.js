const express = require("express");
const cors = require('cors');
const mongoose = require('mongoose');
const { users,todos } = require('./database');

async function main() {
  await mongoose.connect('mongodb+srv://armen1920:sencho2015@cluster0.g8exh4t.mongodb.net/todoDB', { useNewUrlParser: true });
}
main();

const PORT = 3001;
const app = express();
app.use(express.json());
app.use(cors());


app.get('/users',async (req, res) => {
  res.send(await users.find({}));
});

app.get('/users/:id', async (req, res) => {
  const userTodo = await todos.find({userId:req.params.id});
  res.send(userTodo);
});

app.post('/users/:id/addToDo', async(req, res) => {
  const todo = new todos({
    id:Date.now(),
    task:  req.body.newToDo,
    userId: req.params.id,
    complated: false
  });
  await todo.save(() => {});
  res.send(todo);
})

app.put('/users/:id/update', async(req, res) => {
  const filterCond = { id: req.params.id };
  const filtered = await todos.find({ id: req.params.id });
  filtered.complated = !filtered.complated;
  const updated = await todos.findOneAndUpdate(filterCond, {complated: filtered.complated});
  res.send(updated);
});

app.delete('/users/:id/deleteToDo', async(req,res) => {
  const deletedTask = await todos.deleteMany({userId: req.params.id, complated: true});
  res.send(deletedTask);
});

app.listen(PORT);