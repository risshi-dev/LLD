
#include<Products.hpp>
#include<User.hpp>
#include<NotificationByPhone.hpp>
#include<NotificationByEmail.hpp>

int main() {
    cout << "Welcome To Store"<<endl;

    Products* iphone = new Products("iphone 16", 10);
    Products* samsung = new Products("samsung s21", 30);

    cout << iphone->getName() << " Stocks in store"<<endl;
    cout << samsung->getName() << " Stocks in store"<<endl;

    User* ankita = new User("ankita","test@gmail.com", "9999999999", new EmailNotification());
    User* ankit = new User("ankit","test2@gmail.com", "9999999988", new SmsNotification());

    iphone->updateStock(0);
    iphone->subscribeMe(ankita);

    samsung->updateStock(0);
    samsung->subscribeMe(ankit);

    iphone->updateStock(10);
    samsung->updateStock(20);

}