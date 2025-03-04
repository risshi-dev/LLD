#pragma once
#include<iostream>
#include<Transaction.hpp>
using namespace std;

class DebitTransaction: public Transaction {
    public:
        DebitTransaction(string sender, string reciever, int amount);

};

DebitTransaction::DebitTransaction(string sender, string reciever, int amount) : Transaction(sender, reciever, amount, "DEBIT"){};
