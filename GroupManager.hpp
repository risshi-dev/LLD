#pragma once
#include<Group.hpp>
#include<unordered_map>
#include<mutex>
using namespace std;

class GroupManager
{
private:
    static GroupManager* instance;
    static mutex mtx;
    GroupManager();
    unordered_map<string, Group*> db;
public:
    static GroupManager* getInstance();
    void addGroup(string name, Group* group);
    Group* getGroup(string name);

};

GroupManager* GroupManager::instance = nullptr;
mutex GroupManager::mtx;

GroupManager::GroupManager() {
    cout<<"<< Group Manager >>"<<endl;
}

GroupManager* GroupManager::getInstance() {
    if (GroupManager::instance == nullptr) {
        mtx.lock();
        if (GroupManager::instance == nullptr) {
            GroupManager::instance = new GroupManager();
        }
        mtx.unlock();
    }
    return GroupManager::instance;
}

void GroupManager::addGroup(string name, Group* user) {
    db[name] = user;
}

Group* GroupManager::getGroup(string name) {
    return this->db[name];
}


