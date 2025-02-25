#pragma once
#include<bits/stdc++.h>
#include<Theatre.hpp>
#include<Ticket.hpp>
#include<mutex>
using namespace std;

class TheatreController{
    private:
        TheatreController();
        static TheatreController* instance;
        static mutex mtx;
        unordered_map<City*, vector<Theatre*>> cityToTheatres;
        vector<Theatre*> allTheatres;
    public:
        static TheatreController* getInstance();
        void addTheatres(City* city, Theatre* th);
        vector<Theatre*> getAllTheatre();
        Theatre* findTheatreWIthMovie(City* city, Movie* movie);
        Screen* findScreen(Theatre* theatre, Movie* movie);
        vector<Shows*> availableShows(Screen* screen, Movie* movie);
        Ticket* bookTickets(vector<int> seats, Screen* screen, Theatre* theatre, Shows* show);

};