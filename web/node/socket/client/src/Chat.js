import React, { useEffect, useState } from "react";

function Chat({ socket, username, room }) {
    const[message, setMessage] = useState('');
    const[messageReceived, setMessageReceived] = useState('');

    const sendMessage = async() => {
        if(message) {
            const messageData = {
                room: room,
                author: username,
                message: message
            };
            await socket.emit('sendMessage', messageData);
        }
    };

    useEffect(() => {
        socket.on('receiveMessage', (data) => {
            setMessageReceived(data.message);
        });
    }, [socket]);

    return (
        <div>
            <h2>Start Messaging</h2>
            <input 
                type='text' 
                placeholder='Type a message...' 
                value={message}
                onChange={(evt) => {setMessage(evt.target.value)}}
            />
            <button onClick={sendMessage}>Send</button>
            <h3>{messageReceived}</h3>
        </div>
    );
}

export default Chat;