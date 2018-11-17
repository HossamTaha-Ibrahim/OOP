#include "Client.h"
#include "Account.h"

Client::Client(){}

Client::Client(string n, string add, string p){
    name = n;
    address = add;
    phone = p;
}

/** Setters **/
void Client::setName(string n){
    name = n;
}
void Client::setAddress(string add){
    address = add;
}
void Client::setPhone(string p){
    phone = p;
}
void Client::setAccount(Account* acc){
    account = acc;
}

/** Getters **/
string Client::getName(){
    return name;
}
string Client::getAddress(){
    return address;
}
string Client::getPhone(){
    return phone;
}
Account* Client::getAccount(){
    return account;
}

/** << Operator Overloading **/
ostream& operator<<(ostream &out, Client &client){
    Account* account = client.getAccount();
    out << "Client Name: " << client.name << endl
        << "Client Phone: " << client.phone << endl
        << "Client Address: " << client.address << endl
        << "Account ID: " << account->getAccountID() << " (" << account->getType() << ")" << endl
        << "Balance: " << account->getBalance()<<endl;
    return out;
}
