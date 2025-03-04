#include<UserManager.hpp>
#include<DebitTransaction.hpp>
#include<CreditTransaction.hpp>

class Pay
{
private:
    UserManager* user;
public:
    Pay() {
        cout<<"Welcome to Pay";
        this->user = UserManager::getInstance();
    }
    
    void registerUser(User* user) {
        this->user->registerUser(user->getUserName(), user);
    }

    void transferBalance(string sender, string reciever, int amount);
    void showStatement(string user);
};

void Pay::transferBalance(string sender, string reciever, int amount) {
    User* senderDetails = user->getUser(sender);
    User* recieverDetails = user->getUser(reciever);

    Wallet* senderWallet = senderDetails->getWallet();
    Wallet* recieverWallet = recieverDetails->getWallet();

    bool isMoneyDebited = senderWallet->debitTransaction(amount);
    
    if(!isMoneyDebited) {
        cout<<"Insufficient Balance, cannot proceed further"<<endl;
        return;
    }
    Transaction* debitTransaction = new DebitTransaction(sender, reciever, amount);
    senderWallet->updateStatement(debitTransaction);
    Transaction* creditTransaction = new CreditTransaction(sender, reciever, amount);
    recieverWallet->updateStatement(creditTransaction);
}

void Pay::showStatement(string name) {
    Wallet* wallet = user->getUser(name)->getWallet();
    cout<<name<<" account statement"<<endl;
    wallet->printStatement();
}