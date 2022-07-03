import { useState, useEffect } from 'react';
import Input from './components/Input';
import Movies from './components/Movies';
import Button from './components/Button';
import AddMovieModal from './components/MovieModal';
import movies from './movies';
import './App.css';

function App() {
	const [value, setValue] = useState('');
	const [moviesList, setMoviesList] = useState(movies);
	const [filteredMovies, setFilteredMovies] = useState(moviesList);
	const [modal, setModal] = useState(false);

	useEffect(() => {
		setFilteredMovies(moviesList.filter((elem) => elem.name.toLowerCase().startsWith(value.toLowerCase())));
	}, [value, moviesList]);
	
	useEffect(() => {
		setFilteredMovies(moviesList);
	}, [moviesList]);

	const changeValue = (evt) => {
		setValue(evt.target.value);
	}

	const showModal = () => {
		setModal(true);
	}

	const closeModal = () => {
		setModal(false);
	}

	const deleteMovie = (id) => {
		setMoviesList(moviesList.filter((elem) => elem.id !== id));
	}
	
	return (
		<div className='container'>
			<div className='header'>
				<p>Count: {filteredMovies.length}</p>
				<Input
					type="text"
					placeholder="Search"
					value={value}
					onChange={changeValue}
				/>
				<Button type="button" buttonClick={showModal} buttonText="Add" />
				{modal ? <AddMovieModal moviesList={moviesList} setMoviesList={setMoviesList} closeModal={closeModal}/> : null}
			</div>
			<Movies movies={filteredMovies} deleteMovie={deleteMovie} />
		</div>
	);
}

export default App;