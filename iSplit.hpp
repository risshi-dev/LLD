#pragma once
#include<bits/stdc++.h>
#include<expense.hpp>
using namespace std;

class iSplit{
    public:
        virtual unordered_map<string, double> splitMoney(vector<string> members, int amount) = 0;
};