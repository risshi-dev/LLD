#include<Payment.hpp>

Payment::Payment(int amount) {
    this->status = 0;
    this->amount = amount;
}

void Payment::updatePayment() {
    this->status = 1;
}

int Payment::getBillAmount() {
    return this->amount;
}