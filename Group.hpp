#pragma once
#include<UserManager.hpp>
#include<expense.hpp>
#include<vector>
#include<iGroupAlgo.hpp>
#include<Simplify.hpp>
class Group{
    private:
        string name;
        vector<string> members;
        vector<Expense*> expenses;
        UserManager* userDb = UserManager::getInstance();
        iGroupAlgo* split = new Simplify();
    public:
        Group(string name, vector<string> user);
        void addMembers(string user);
        void removeMember(string user);
        void addExpense(Expense* expense);
        void showGroupSplit();
};

Group::Group(string name, vector<string> user) {
    this->name = name;
    this->members = user;
}

void Group::addMembers(string user) {
    this->members.push_back(user);
}

void Group::removeMember(string name) {

    int index = 0;
    for(string usr: this->members) {
        if(usr == name) break;
        index++;
    }
    this->members.erase(this->members.begin()+index);
}

void Group::addExpense(Expense* expense) {
    this->expenses.push_back(expense);
}

void Group::showGroupSplit() {
    auto split = this->split->simplifyDebts(this->members, this->expenses);

    for(auto i: split) {
        cout<<i.first<<" :: "<<i.second<<endl;
    }
}