import './App.css';
import Chat from './Chat';
import io from 'socket.io-client';
import { useState } from 'react';

const socket = io.connect('http://localhost:3001');

function App() {
  const[username, setUsername] = useState('');
  const[room, setRoom] = useState('');

  const joinRoom = () => {
    if(username && room) {
      socket.emit('joinRoom', room);
    }
  }

  return (
    <div className="App">
      <h2>Chat Room</h2>
      <input 
        type='text' 
        placeholder='Username' 
        value={username} 
        onChange={(evt) => {setUsername(evt.target.value)}}/>
      <input 
        type='text' 
        placeholder='Room Id' 
        value={room}
        onChange={(evt) => {setRoom(evt.target.value)}}/>
      <button onClick={joinRoom}>Join the room</button>
      <Chat socket={socket} username={username} room={room} />
    </div>
  );
}

export default App;