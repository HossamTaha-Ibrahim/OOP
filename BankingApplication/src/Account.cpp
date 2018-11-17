#include "Account.h"
#include "Client.h"
Account::Account()
{
    balance = 0;
    //accountID = "FCI-";
}

/** Setters **/
void Account::setAccountID(string id){
    accountID = id;
}
void Account::setBalance(double b){
    balance = b;
}

void Account::setOwner(Client* o){
    owner = o;
}

/** Getters **/
Client* Account::getOwner(){
    return owner;
}

string Account::getType(){
    return this->type;
}
string Account::getAccountID(){
    return this->accountID;
}
double Account::getBalance(){

    return this->balance;
}


bool Account::withdraw(double amount){return false;}

bool Account::deposit(double amount){return false;}

ostream& operator<<(ostream &out, Account &account){

    out << "Account ID: " << account.accountID << endl
        << "Account Type: " << account.type << endl
        << "Current Balance: " << account.balance << endl;
    return out;
}
