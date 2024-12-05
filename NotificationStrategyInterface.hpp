#pragma once
#include<iostream>
#include<UserInterface.hpp>
using namespace std;

class iNotification{
    public:
        virtual void sendNotification(iUser*) = 0;
};