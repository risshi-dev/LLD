#pragma once
#include<iSplit.hpp>

class EqualSplit: public iSplit{
    public:
        unordered_map<string, double> splitMoney(vector<string> members, int amount);
};

unordered_map<string, double> EqualSplit::splitMoney(vector<string> members, int amount) {
    unordered_map<string, double> split;
    double splitAmt = amount/members.size();
    for(string usr: members) split[usr] = splitAmt;

    return split;
}
