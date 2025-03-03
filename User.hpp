#pragma once
#include<iostream>
using namespace std;

class User
{
private:
    string name;
    int mobileNumber;
    string email;
public:
    User(string name, int number, string email);
    // getter
    string getName();
    int getNumber();
    string getEmail();

    // Interface in future
    void notifyMe(int amount);
};

User::User(string name, int number, string email)
{
    this->name = name;
    this->mobileNumber = number;
    this->email = email;
}

string User::getEmail() {
    return this->email;
}

string User::getName() {
    return this->name;
}

int User::getNumber() {
    return this->mobileNumber;
}

void User::notifyMe(int amount) {
    cout<<"Expense added: "<<amount;
}
