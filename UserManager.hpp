#pragma once
#include<User.hpp>
#include<unordered_map>
#include<mutex>
using namespace std;

class UserManager
{
private:
    static UserManager* instance;
    static mutex mtx;
    UserManager();
    unordered_map<string, User*> db;
public:
    static UserManager* getInstance();
    void addUser(string name, User* user);
    User* getUser(string name);

};

UserManager* UserManager::instance = nullptr;
mutex UserManager::mtx;

UserManager::UserManager() {
    cout<<"<< User Manager >>"<<endl;
}

UserManager* UserManager::getInstance() {
    if (UserManager::instance == nullptr) {
        mtx.lock();
        if (UserManager::instance == nullptr) {
            UserManager::instance = new UserManager();
        }
        mtx.unlock();
    }
    return UserManager::instance;
}

void UserManager::addUser(string name, User* user) {
    db[name] = user;
}

User* UserManager::getUser(string name) {
    return this->db[name];
}


