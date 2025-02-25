#pragma once
#include<bits/stdc++.h>
#include<mutex>
#include<Movie.hpp>
#include<City.hpp>
using namespace std;


class MovieController
{
    private:
        MovieController();
        static MovieController* instance;
        static mutex mtx;
        unordered_map<City*, vector<Movie*>> cityToMovieDb;
        vector<Movie*> allMovies;
    public:
        static MovieController* getInstance();
        void addMovie(City* city, Movie* movie);
        vector<Movie*> getCityWiseMovies(City* city);
        Movie* getMovieDetails(City* city, string name);
};