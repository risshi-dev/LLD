#include<City.hpp>
#include<MovieController.hpp>
#include<Movie.hpp>
#include<Theatre.hpp>
#include<Screen.hpp>
#include<Seats.hpp>
#include<TheatreController.hpp>
#include<Shows.hpp>

int main() {
    cout<<"welcome to bookmyshow"<<endl;

    //Available Cities
    City* blr = new City(101, "Banglore");
    City* del = new City(102, "Delhi");

    //Available Movies
    Movie* race = new Movie(1, "Race", 149);
    Movie* znmd = new Movie(2, "ZNMD", 156);

    //MovieController
    MovieController* instance = MovieController::getInstance();

    instance->addMovie(del, race);
    instance->addMovie(del, znmd);
    instance->addMovie(blr, znmd);

    //Add theatre
    Theatre* t1 = new Theatre(1, blr);
    Theatre* t2 = new Theatre(2, del);
    
    //Add Screens;
    vector<Seats*> seat1;
    for(int i = 1; i<=100; i++) {
        if(i <=30) {
            seat1.push_back(new Seats(i, (i/10)+1, "SILVER", 200));
        } else if ( i <= 80) {
            seat1.push_back(new Seats(i, (i/10)+1, "GOLD", 350));

        } else {
            seat1.push_back(new Seats(i, (i/10)+1, "LOUNGE", 500));
        }
    }

    vector<Seats*> seat2;
    for(int i = 1; i<=90; i++) {
        if(i <=30) {
            seat2.push_back(new Seats(i, (i/10)+1, "SILVER", 150));
        } else if ( i <= 80) {
            seat2.push_back(new Seats(i, (i/10)+1, "GOLD", 200));

        } else {
            seat2.push_back(new Seats(i, (i/10)+1, "LOUNGE", 500));
        }
    }

    Screen* screen1 = new Screen(1, seat1);
    Screen* screen2 = new Screen(2, seat2);

    //Add show;
    Shows* show1 = new Shows(1, race, "7:30");
    Shows* show2 = new Shows(2, znmd, "7:30");
    Shows* show3 = new Shows(3, znmd, "10:30");

    screen1->addShows(show1);
    screen1->addShows(show3);
    screen2->addShows(show2);

    //complete Theatre;
    t1->addMovieScreens(screen1);
    t2->addMovieScreens(screen2);

    //Add Theatre
    TheatreController* theatreController = TheatreController::getInstance();
    theatreController->addTheatres(blr, t1);
    theatreController->addTheatres(del, t2);

    Movie* movieToBook = instance->getMovieDetails(blr, "ZNMD");

    Theatre* theatreToBook = theatreController->findTheatreWIthMovie(blr, movieToBook);
    Screen* screenToBook = theatreController->findScreen(theatreToBook, movieToBook);
    vector<Shows*> shows = theatreController->availableShows(screenToBook, movieToBook);
    Ticket* ticket = theatreController->bookTickets({1, 70, 100}, screenToBook, theatreToBook, shows[0]);
    ticket->printTicket();

    vector<Shows*> shows2 = theatreController->availableShows(screenToBook, movieToBook);
    Ticket* ticket2 = theatreController->bookTickets({90}, screenToBook, theatreToBook, shows2[0]);
    ticket2->printTicket();
    
}