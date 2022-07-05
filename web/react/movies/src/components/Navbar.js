import './Navbar.css'
import { Link } from 'react-router-dom';

function Navbar() {
    return(
        <div className='navbar'>
            <Link to="/home" id= "nav-item" >Home</Link>
            <Link to="/movies" id= "nav-item" >Movies</Link>  
        </div>
    ); 
}

export default Navbar;