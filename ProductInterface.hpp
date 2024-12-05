#pragma once
#include<UserInterface.hpp>

using namespace std;

class iProduct{
    public: 
        virtual void updateStock(int) = 0;
        virtual int getStock() = 0;
        virtual void subscribeMe(iUser*) = 0;
        virtual void notifyUsers() = 0;
};