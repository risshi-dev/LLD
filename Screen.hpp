#pragma once
#include<bits/stdc++.h>
#include<Shows.hpp>
#include<Seats.hpp>
using namespace std;

class Screen
{
    public:
        Screen(int id, vector<Seats*> seats);
        int id;
        vector<Shows*> showsPerScreen;
        vector<Seats*> seats;
        unordered_map<Shows*, vector<Seats*>> showToSeatMap;
        void addShows(Shows* show);
};