#include<Shows.hpp>

Shows::Shows(int id, Movie* movie, string time) {
    this->show_id = id;
    this->movie = movie;
    this->start_time = time;
}