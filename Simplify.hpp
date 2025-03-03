#pragma once
#include<iGroupAlgo.hpp>
#include<UserManager.hpp>

class Simplify: public iGroupAlgo {
    private:
        UserManager* userManager = UserManager::getInstance();
    public:
        unordered_map<string, double> simplifyDebts(vector<string> members, vector<Expense*> expenses);
};

unordered_map<string, double> Simplify::simplifyDebts(vector<string> members, vector<Expense*> expenses) {
    unordered_map<string, double> memberSplit;
    for(Expense* expense: expenses) {
        unordered_map<string, double> expSplit = expense->getSplit();
        for(auto split: expSplit) {
            if(memberSplit.find(split.first) != memberSplit.end()) {
                memberSplit[split.first] += split.second;
            } else {
                memberSplit[split.first] = split.second;
            }
        }
    }
    return memberSplit;
}