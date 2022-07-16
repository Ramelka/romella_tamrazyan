import {useState,useEffect,useCallback} from 'react'
import { useParams } from 'react-router-dom';
import './ToDo.css'

function ToDo() {
  const[data,setData] = useState([]);
  const[newToDo,setNewToDo] = useState('')
  const params = useParams();

  useEffect(() => {
    fetch(`http://localhost:3001/users/${params.id}`)
      .then((res) => res.json())
      .then((e) => setData(e));
  }, []);


  const addToDo = () => {
    fetch(`http://localhost:3001/users/${params.id}/addToDo`,{
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({newToDo})
    })
    .then((res) => res.json())
    .then((todo) =>{
        setData([...data, todo])
  })};

  const changeTodoStatus = (id) => {
    fetch(`http://localhost:3001/users/${id}/update`, { method: 'POST' })
      .then(() => {
        setData((prevTodos) => {
          return prevTodos.map((todo) => {
            if (todo.id === id) {
              // console.log(id)
              todo.isCompleted = !todo.isCompleted;
            }
            return todo;
          });
        });
      })
  }

  const deleteToDo = () => {
    console.log("A")
    fetch(`http://localhost:3001/users/${params.id}/deleteToDo`, {
      method: 'POST'
    })
      .then(() => {
        setData(data.filter((todo)=>{
          if(todo.isCompleted === true){
            return false;
          }
          return true;
        }));
      });
  }

  return (
    <>
      <div className='todo-div'>
        <ul className='list'>
        {data.map((data) => {
          return (
            <li className='list_item' key={data.id}>
                <input className='checkbox' type={'checkbox'} checked = {data.isCompleted} onChange={() => changeTodoStatus(data.id)} />
                {data.task}
              </li>
            );
          })}
        </ul>
        <input type='text' value={newToDo} onChange = {(e) => setNewToDo(e.target.value)}/>
      <button onClick={addToDo} >Add</button>
      <button onClick={deleteToDo}>Delete</button>
      </div>
  </>
  )}

export default ToDo;