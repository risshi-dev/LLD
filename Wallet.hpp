#pragma once
#include<iostream>
#include<Transaction.hpp>
#include<AccountStatement.hpp>
using namespace std;

class Wallet{
    private:
        int balance;
        AccountStatement* statement;
    public:
        Wallet(int balance);
        bool debitTransaction(int amount);
        void creditTransaction(int amount);
        void updateStatement(Transaction* transaction);
        void printStatement();

};

Wallet::Wallet(int balance) {
    this->balance = balance;
    this->statement = new AccountStatement();
}

bool Wallet::debitTransaction(int amount) {
    if (amount < balance) {
        this->balance -= amount;
        return true;
    }
    return false;
}

void Wallet::creditTransaction(int amount) {
    this->balance += amount;
}

void Wallet::updateStatement(Transaction* trnx) {
    this->statement->addTransaction(trnx);
}

void Wallet::printStatement() {
    this->statement->printStatement();
}