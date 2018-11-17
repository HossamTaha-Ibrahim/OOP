#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
using namespace std;

/** Forward declaration of "Account" for cyclic dependency **/
class Account;
/***********************************************************/
class Client
{
    private:
        string name;
        string address;
        string phone;
        Account* account;
    public:
        Client();
        Client(string, string, string);
        void setName(string);
        void setAddress(string);
        void setPhone(string);
        void setAccount(Account*);

        string getName();
        string getAddress();
        string getPhone();
        Account* getAccount();
        friend ostream& operator<<(ostream &out, Client &client);



};

#endif // CLIENT_H
