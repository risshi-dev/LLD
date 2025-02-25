#pragma once
#include<iostream>
using namespace std;

class Movie{
    public:
        int movie_id;
        string movie_name;
        int duration;
        Movie(int id, string name, int duration);
};
