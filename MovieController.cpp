#include<MovieController.hpp>
MovieController* MovieController::instance = nullptr;
mutex MovieController::mtx;

MovieController::MovieController() {
    this->allMovies.resize(0);
}

MovieController* MovieController::getInstance() {
    if(MovieController::instance == nullptr) {
        mtx.lock();
        MovieController::instance = new MovieController();
        mtx.unlock();
    }
    return MovieController::instance;   
}

void MovieController::addMovie(City* city, Movie* movie) {
    this->allMovies.push_back(movie);
    this->cityToMovieDb[city].push_back(movie);
}

vector<Movie*> MovieController::getCityWiseMovies(City* city) {
    if(this->cityToMovieDb.find(city) != this->cityToMovieDb.end()) {
        return this->cityToMovieDb[city];
    } else {
        return {};
    }
}

Movie* MovieController::getMovieDetails(City* city, string movie) {

    if(this->cityToMovieDb.find(city) != this->cityToMovieDb.end()) {
        for(Movie* movieElement: this->cityToMovieDb[city]) {
            if(movieElement->movie_name == movie) {
                return movieElement;
            }
        };
    }
}