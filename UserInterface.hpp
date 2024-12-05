#pragma once
#include<bits/stdc++.h>
using namespace std;

class iUser{
    public:
        virtual void update(iUser*) = 0;
        virtual string getEmail()= 0;
        virtual string getMobile() = 0;
};