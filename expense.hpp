#pragma once
#include<User.hpp>
#include<vector>
#include<UserManager.hpp>
#include<iSplit.hpp>

class Expense{
    private:
        string name;
        int amount;
        vector<string> friends{};
        unordered_map<string, double> split;
        iSplit* splitAlgo;
        UserManager* userDb = UserManager::getInstance();
    public:
        Expense(string name, vector<string> members, int amount, iSplit* algo);
        void addFriend(string name);
        void removeFriend(string name);
        void updateSplitAlgo();
        void showSplit();
        unordered_map<string, double> getSplit();
};
void Expense::updateSplitAlgo() {
    this->split = this->splitAlgo->splitMoney(this->friends, amount);
    for(string name: this->friends) {
        userDb->getUser(name)->notifyMe(split[name], this->name);
    }
}
Expense::Expense(string name, vector<string> members, int amount, iSplit* algo) {
    this->name = name;
    this->friends = members;
    this->amount = amount;
    this->splitAlgo = algo;
    this->updateSplitAlgo();
}

void Expense::addFriend(string name) {
    this->friends.push_back(name);
    this->updateSplitAlgo();
}

void Expense::removeFriend(string name) {
    int index = 0;
    for(string usr: this->friends) {
        if(usr == name) break;
        index++;
    }
    this->friends.erase(this->friends.begin()+index);
    this->updateSplitAlgo();
}

void Expense::showSplit() {
    for(auto i: this->split) {
        cout<<i.first<<" :: "<<i.second<<endl;
    }
}

unordered_map<string, double> Expense::getSplit() {
    return this->split;
}