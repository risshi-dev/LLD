#include<Theatre.hpp>

Theatre::Theatre(int id, City* city) {
    this->id = id;
    this->city = city;
}

void Theatre::addMovieScreens(Screen* screen) {
    this->screens.push_back(screen);
}