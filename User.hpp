#pragma once
#include<UserInterface.hpp>
#include<NotificationStrategyInterface.hpp>

class User: public iUser{
    string name;
    string email;
    string mobile;
    iNotification* notification;
    
    public:
        User(string name, string email, string mobile, iNotification* notificationType) {
            this->name = name;
            this->email = email;
            this->mobile = mobile;
            this->notification = notificationType;
        }
        void update(iUser* user) {
            notification->sendNotification(user);
        }
        string getEmail() {
            return this->email;
        }
        string getMobile() {
            return this->mobile;
        }
};