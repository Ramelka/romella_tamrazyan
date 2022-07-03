import { useState } from 'react';
import Button from './Button';
import Input from './Input';
import './MovieModal.css';

function AddMovieModal(props) {
    const [name, setName] = useState('');
    const [description, setDescription] = useState('');

    const addMovie = () => {
        const newMovie = {
            id: Date.now(),
            name,
            description,
            image: '/images/image.webp',
        };
        props.setMoviesList([...props.moviesList, newMovie]);
        props.closeModal();
    }

    const changeName = (evt) => {
        setName(evt.target.value);
    }

    const changeDescription = (evt) => {
        setDescription(evt.target.value);
    }
    
    return (
        <div className="modal">
            <div className="modal-content">
                <span className="close" onClick={props.closeModal}>&times;</span>
                <h2>Add film</h2>
                <Input 
                    type="text"
                    value={name}
                    placeholder="Name"
                    onChange={changeName}
                />
                <Input 
                    type="text"
                    value={description}
                    placeholder="Description"
                    onChange={changeDescription}
                />
                <Button
                    type="button"
                    buttonClick={addMovie}
                    buttonText="Add"
                />
            </div>
        </div>
    );
}

export default AddMovieModal;