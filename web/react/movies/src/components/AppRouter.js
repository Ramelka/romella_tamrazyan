import { Routes, Route } from "react-router-dom";
import HomePage from "./pages/home/HomePage";
import MoviesPage from "./pages/movies/MoviesPage";
import NotFoundPage from "./pages/notFound/NotFoundPage";

function AppRouter() {
    return(
            <Routes> 
                <Route path="/" />
                <Route path="/home" element={<HomePage />} />
                <Route path="/movies" element={<MoviesPage />} />
                {/* <Route path="/movies/:id" /> */}
                <Route path="*" element={<NotFoundPage />} /> 
            </Routes>
    )
}

export default AppRouter;