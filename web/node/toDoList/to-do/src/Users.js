import {useState,useEffect} from 'react'
import { Link } from "react-router-dom";
import './App.css';

const Users = () => {
  const [users, setUsers] = useState([]);

  useEffect(() => {
    fetch('http://localhost:3001/users')
      .then((res) => res.json())
      .then(setUsers)
  }, []);

  return (
    <>
      <div className='users-div'>
        <ul className='users-block'>
          {users.map((user) => {
            return (
              <li className='user' key={user.id}>
                <Link to={`/users/${user.id}`} >
                  {user.username}
                </Link>
              </li>
            );
            })}
        </ul>
      </div>
    </>
  )
}

export default Users;