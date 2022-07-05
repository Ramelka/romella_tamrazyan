import React from 'react'
import './Movies.css';
import Button from './reusable/button/Button'
import { Link } from 'react-router-dom';

function Movies(props) {
    const moviesItems = props.movies.map((elem) => {
        return (
            <div className='movie' key={elem.id}>
                <h1>{elem.name}</h1>
                <p>{elem.description}</p>
                <img src={elem.image} alt={elem.name} />
                <Button
                    type="button"
                    buttonText="Delete"
                    buttonClick={() => props.deleteMovie(elem.id)}
                />
                <Link to={`/movies/${elem.id}`}>Go to</Link>
            </div>
        )
    });

    return (
        <div className='movies'>
            {moviesItems}
        </div>
    );
}

export default Movies;