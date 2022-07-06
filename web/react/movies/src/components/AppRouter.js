import React  from "react";
import { useState, createContext } from "react";
import { Routes, Route } from "react-router-dom";
import HomePage from "./pages/home/HomePage";
import MoviesPage from "./pages/movies/MoviesPage";
import GoToMovie from "./pages/goToMovie/GoToMovie"
import NotFoundPage from "./pages/notFound/NotFoundPage";
import movies from '../movies';

export const MovieContext = createContext(null);

function AppRouter() {
    const [moviesList, setMoviesList] = useState(movies);
    return (
        <MovieContext.Provider value={{
			moviesList, setMoviesList,
		}}>
            <Routes> 
                <Route path="/" />
                <Route path="/home" element={<HomePage />} />
                <Route path="/movies" element={<MoviesPage />} />
                <Route path="/movies/:id" element={<GoToMovie />} />
                <Route path="*" element={<NotFoundPage />} /> 
            </Routes>
            </MovieContext.Provider>
    )
}

export default AppRouter;