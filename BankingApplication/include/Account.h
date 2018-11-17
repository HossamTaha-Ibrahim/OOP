#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;

/** Forward declaration of "Client" for cyclic dependency **/
class Client;
/***********************************************************/
class Account
{


    protected:
        string accountID;
        string type;
        double balance;
        Client *owner;

    public:
        Account();

        void setAccountID(string);
        void setBalance(double);
        void setType(string);
        void setOwner(Client*);

        string getAccountID();
        double getBalance();
        string getType();
        Client* getOwner();

        virtual bool withdraw(double);
        virtual bool deposit(double);

        virtual void setMinBalance(double){}
        virtual double getMinBalance(){}

        friend ostream& operator<<(ostream &out, Account &account);


};

#endif // ACCOUNT_H
