#include<Seats.hpp>

Seats::Seats(int number, int row, string type, int rate) {
    this->seatNumber = number;
    this->row = row;
    this->type = type;
    this->status = 0;
    this->seatRate = rate;
}

void Seats::updateStatus() {
    this->status = 1;
}