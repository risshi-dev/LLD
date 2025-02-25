#pragma once
#include<Movie.hpp>

class Shows{
    public:
        int show_id;
        Movie* movie;
        string start_time;
        Shows(int id, Movie* movie, string time);
};