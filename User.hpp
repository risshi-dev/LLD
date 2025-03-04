#pragma once
#include<iostream>
#include<Wallet.hpp>
using namespace std;

class User{
    private:
        int user_id;
        string name;
        Wallet* wallet;
    public:
        User(int user_id, string name, Wallet* wallet);
        string getUserName();
        Wallet* getWallet();
};

User::User(int user_id, string name, Wallet* wallet) {
    this->user_id = user_id;
    this->name = name;
    this->wallet = wallet;
}

string User::getUserName() {
    return this->name;
}

Wallet* User::getWallet() {
    return this->wallet;
}