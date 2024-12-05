#pragma once
#include<ProductInterface.hpp>

class Products: public iProduct{
    int productId;
    int stock;
    string name;
    vector<iUser*> userSubscribed;
    public:
        Products(string name, int stock) {
            this->name = name;
            this->stock = stock;
        }
        void updateStock(int stock) {
            if(stock == 0) {
                cout<<this->name<<" Out Of Stock"<<endl;
                this->stock = stock;
                return;
            }
            if(this->stock == 0) {
                notifyUsers();
            }
            this->stock += stock;
        }
        int getStock() {
            return this->stock;
        }
        string getName() {
            return this->name;
        }
        void subscribeMe(iUser* user) {
            this->userSubscribed.push_back(user);
        };
        void notifyUsers(){
            for(iUser* users: this->userSubscribed) {
                users->update(users);
            }
        };
};