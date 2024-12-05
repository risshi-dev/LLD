#pragma once
#include<NotificationStrategyInterface.hpp>

class EmailNotification: public iNotification {
    public:
        void sendNotification(iUser* user) {
            cout << user->getEmail() << " Sent!!!!"<<endl;
        }
};