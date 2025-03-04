#pragma once
#include<bits/stdc++.h>
#include<Transaction.hpp>
using namespace std;

class AccountStatement {
    private:
        vector<Transaction*>  statement;
    public:
        void addTransaction(Transaction* transaction) {
            this->statement.push_back(transaction);
        }

        void printStatement();
};

void AccountStatement::printStatement() {
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Sender"<<" | "<<"Reciever"<<" | "<<"Amount"<<" | "<<"Status"<<endl;
    for(auto transaction: statement) {
        cout<<transaction->getSender()<<" | "<<transaction->getReciever()<<" | "<<transaction->getAmount()<<" | "<<transaction->getType()<<endl;
    }
    cout<<"----------------------------------------------------"<<endl;
    cout<<endl;
}