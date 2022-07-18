const mongoose  = require('mongoose');
const { Schema } = mongoose;

const userSchema = new Schema({
  id:Number,
  username: String
});

const todosSchema = new Schema({
  id:Number,
  task: String,
  userId: Number,
  complated: Boolean
});

const users = mongoose.model('users',userSchema);
const todos = mongoose.model('todos',todosSchema);
module.exports = {users,todos};