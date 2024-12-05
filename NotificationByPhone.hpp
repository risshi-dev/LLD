#pragma once
#include<NotificationStrategyInterface.hpp>

class SmsNotification: public iNotification {
    public:
        void sendNotification(iUser* user) {
            cout << user->getMobile() << " Sent!!!!"<<endl;
        }
};