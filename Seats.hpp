#pragma once
#include<iostream>
using namespace std;

class Seats{
    public:
        int seatNumber;
        int row;
        int status;
        string type;
        int seatRate;
        Seats(int number, int row, string type, int rate);
        void updateStatus();
};