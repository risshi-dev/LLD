#include<TheatreController.hpp>

mutex TheatreController::mtx;
TheatreController* TheatreController::instance = nullptr;

TheatreController::TheatreController() {
}

TheatreController* TheatreController::getInstance() {
    if(TheatreController::instance == nullptr) {
        mtx.lock();
        if(TheatreController::instance == nullptr) {
            TheatreController::instance = new TheatreController();
        }
        mtx.unlock();
    }
    return TheatreController::instance;
}

void TheatreController::addTheatres(City* city, Theatre* th) {
    this->allTheatres.push_back(th);
    this->cityToTheatres[city].push_back(th);
}

vector<Theatre*> TheatreController::getAllTheatre() {
    return this->allTheatres;
}

Theatre* TheatreController::findTheatreWIthMovie(City* city, Movie* movie) {
    auto allTheatresInCity = this->cityToTheatres[city];

    for(Theatre* theatre: allTheatresInCity) {
        for(auto screen: theatre->screens) {
            for(auto show : screen->showsPerScreen) {
                if(show->movie == movie) {
                    return theatre;
                }
            }
        }
    }
}

Screen* TheatreController::findScreen(Theatre* theatre, Movie* movie) {

    for(auto screen: theatre->screens) {
        for(auto show : screen->showsPerScreen) {
            if(show->movie == movie) {
                return screen;
            }
        }
    }   
}

vector<Shows*> TheatreController::availableShows(Screen* screen, Movie* movie) {
    vector<Shows*> allAvailableShows;
    for(auto show : screen->showsPerScreen) {
        if(show->movie == movie) {
            cout <<":: "<<show->start_time<<" ::"<<endl;

            for(auto it: screen->showToSeatMap[show]) {
                if(it->status == 0) {
                    cout<<it->seatNumber<<" ";
                }
            }
            allAvailableShows.push_back(show);
            cout<<endl<<endl;
        }
    }
    return allAvailableShows;

}

Ticket* TheatreController::bookTickets(vector<int> seats, Screen* screen, Theatre* theatre, Shows* show) {
    auto allSeats = screen->showToSeatMap[show];
    vector<Seats*> allBookedSeats;
    int bill = 0;
    for(int i : seats) {
        allSeats[i-1]->updateStatus();
        allBookedSeats.push_back(allSeats[i-1]);
        bill += allSeats[i-1]->seatRate;
    }

    Ticket* ticket = new Ticket(show, screen, theatre, allBookedSeats, bill);
    return ticket;
}
