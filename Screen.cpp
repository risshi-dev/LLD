#include<Screen.hpp>

Screen::Screen(int id, vector<Seats*> seats) {
    this->id = id;
    this->seats = seats;
}

void Screen::addShows(Shows* show) {
    this->showsPerScreen.push_back(show);
    this->showToSeatMap[show] = this->seats;
}