#pragma once
#include<bits/stdc++.h>
#include<Theatre.hpp>
#include<Shows.hpp>
#include<Payment.hpp>
using namespace std;


class Ticket{
    private:
        Shows* movie;
        Screen* screen;
        Theatre* theatre;
        Payment* payment;
        vector<Seats*> seatsInfo;
    public:
        Ticket(Shows* movie, Screen* screen, Theatre* theatre, vector<Seats*> seats, int bill);
        void printTicket();
    
};