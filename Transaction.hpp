#pragma once
#include<iostream>
#include<User.hpp>
using namespace std;

class Transaction {
    static int transactions;
    private:
        int uid;
        string sender;
        string reciever;
        int amount;
        string type;
    public:
        Transaction(string sender, string reciever, int amount, string type);
        string getSender() {
            return this->sender;
        }
        string getReciever() {
            return this->reciever;
        }
        int getAmount() {
            return this->amount;
        }
        string getType() {
            return this->type;
        }

};

int Transaction::transactions = 1;

Transaction::Transaction(string sender, string reciever, int amount, string type) {
    this->sender = sender;
    this->reciever = reciever;
    this->amount = amount;
    this->type = type;
    this->uid = Transaction::transactions++;
}