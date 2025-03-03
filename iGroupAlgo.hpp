#pragma once
#include<iostream>
#include<unordered_map>
#include<expense.hpp>
using namespace std;

class iGroupAlgo{
    public:
        virtual unordered_map<string, double> simplifyDebts(vector<string> members, vector<Expense*> expenses) = 0;
};