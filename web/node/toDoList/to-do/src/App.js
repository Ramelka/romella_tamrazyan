import React from "react";
import ToDo from "./ToDo";
import {BrowserRouter,Routes,Route} from 'react-router-dom' 
import Users from './Users'

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element = {<Users/>} />
        <Route path="/users/:id" element = {<ToDo/>} />
      </Routes>
    </BrowserRouter>
  );
}

export default App;