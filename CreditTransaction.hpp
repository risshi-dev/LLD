#pragma once
#include<iostream>
#include<Transaction.hpp>
using namespace std;

class CreditTransaction: public Transaction {
    public:
        CreditTransaction(string sender, string reciever, int amount);
};

CreditTransaction::CreditTransaction(string sender, string reciever, int amount) : Transaction(sender, reciever, amount, "CREDIT"){};
