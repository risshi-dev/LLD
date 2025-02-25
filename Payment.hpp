#include<iostream>
using namespace std;
class Payment {
    private:    
        int status;
        int amount;
    public:
        Payment(int amount);
        void updatePayment();
        int getBillAmount();

};