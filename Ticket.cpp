#include<Ticket.hpp>

Ticket::Ticket(Shows* movie, Screen* screen, Theatre* theatre, vector<Seats*> seats, int bill) {
    this->movie = movie;
    this->screen = screen;
    this->theatre = theatre;
    this->seatsInfo = seats;
    this->payment = new Payment(bill);
}

void Ticket::printTicket() {
    cout<<"Theatre: "<<this->theatre->id<<endl;
    cout<<"Movie: "<<this->movie->movie->movie_name<<endl;
    cout<<"Timing: "<<this->movie->start_time<<endl;
    cout<<"Screen: "<<this->screen->id<<endl;
    cout<<"Seats: ";
    for(auto seat: seatsInfo) cout<<seat->seatNumber<<" ";
    cout<<endl;
    cout<<"Bill: "<<this->payment->getBillAmount()<<endl;
    cout<<endl<<endl;

}