#include<UserManager.hpp>
#include<expense.hpp>
#include<EqualSplit.hpp>
#include<GroupManager.hpp>
#include<Group.hpp>
int main() {

    User* rishi = new User("rishi", 111111, "test@email.com");
    User* udbhav = new User("udbhav", 222222, "test1@email.com");
    User* ujjwal = new User("ujjwal", 333333, "test2@email.com");
    User* kuldeep = new User("kuldeep", 333333, "test2@email.com");

    UserManager* userMgr = UserManager::getInstance();

    userMgr->addUser("rishi", rishi);
    userMgr->addUser("udbhav", udbhav);
    userMgr->addUser("ujjwal", ujjwal);
    userMgr->addUser("kuldeep", kuldeep);

    Group* paisa = new Group("paisa", {"rishi", "udbhav", "ujjwal"});

    GroupManager* grpManager = GroupManager::getInstance();
    grpManager->addGroup("paisa", paisa);

    vector<string> party{"rishi", "udbhav"};
    iSplit* algo = new EqualSplit();
    Expense* expn = new Expense("party", party, 1000, algo);

    paisa->addExpense(expn);

    // paisa->showGroupSplit();

    expn->addFriend("ujjwal");

    // paisa->showGroupSplit();


    return 0;
}