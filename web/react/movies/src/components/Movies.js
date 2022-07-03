import './Movies.css';
import Button from './Button'

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