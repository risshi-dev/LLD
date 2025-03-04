#include<Pay.hpp>

int main() {

    Pay* amazon = new Pay();
    Wallet* walletA = new Wallet(1000);
    Wallet* walletB = new Wallet(3000);
    Wallet* walletC = new Wallet(5000);


    User* userA = new User(1, "rishi", walletA);
    User* userB = new User(1, "aman", walletB);
    User* userC = new User(1, "ujjwal", walletC);


    amazon->registerUser(userA);
    amazon->registerUser(userB);
    amazon->registerUser(userC);
    
    amazon->transferBalance("rishi", "aman", 100);
    amazon->transferBalance("aman", "aman", 400);
    amazon->transferBalance("ujjwal", "rishi", 400);

    amazon->showStatement("rishi");
    amazon->showStatement("aman");
    amazon->showStatement("ujjwal");
}