#pragma once
#include<City.hpp>
#include<iostream>
#include<Screen.hpp>
using namespace std;


class Theatre{
    public:
        int id;
        string address;
        City* city;
        vector<Screen*> screens;
        Theatre(int id, City* city);
        void addMovieScreens(Screen* screen);
};