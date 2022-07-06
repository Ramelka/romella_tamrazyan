import { useContext, useEffect, useState } from "react";
import { useParams } from "react-router-dom";
import { MovieContext } from "../../AppRouter"
import "../../Movies.css"

function GoToMovie() {
    const { moviesList }  = useContext(MovieContext);
    const { id } = useParams();
    const [movies, setMovies] = useState({});

    useEffect (() => {
        console.log(id);
        setMovies(moviesList.find((elem) => elem.id === Number(id)))
    }, []);
    console.log(moviesList);
    return (
        <div className="movieItem">
            <div className='movieInfo'>
                <h1>{movies.name}</h1>
                <p>{movies.description}</p>
                <img src={movies.image} alt={movies.name} />
            </div>
        </div>
    )
}

export default GoToMovie;