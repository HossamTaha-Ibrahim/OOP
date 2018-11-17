/** Main Application Interface **/

#include <iostream>
#include <vector>
#include <sstream>
#include "Client.h"
#include "Account.h"
#include "BankAccount.h"
#include "SavingsBankAccount.h"
using namespace std;

/** Functions Prototypes **/
void DisplayMainMenu();
void createAccount();
void listAllAccounts();
void wihdrawMoney();
void depositMoney();
string intToString(int );

/** Global Variable, act as Database **/
vector <Client> clients;

int main()
{
    int choice = -1;
    while (choice != 5){

        DisplayMainMenu();
        cin >> choice;
        switch(choice){

            case 1:
                createAccount();
                break;
            case 2:
                listAllAccounts();
                break;
            case 3:
                wihdrawMoney();
                break;
            case 4:
                depositMoney();
                break;

            case 5:
                break;
            default:
                cout << "Enter a valid choice [1-4]!!!" <<endl<<endl;

        }

    }
    return 0;
}


/** Display Main Menu **/
void DisplayMainMenu(){

cout << "Welcome to FCI Banking Application\n" <<endl;
    cout << "1. Create a new account" << endl
         << "2. List clients and accounts" << endl
         << "3. Withdraw money" << endl
         << "4. Deposit money" << endl
         << "\nPlease enter your choice >>> " ;
}

/*************************************************************************/
/** Create new account and add that account to DB **/
/** Account can be Basic or Savings account **/
void createAccount(){
    string name, address, phone;
    int accountType;
    double initBalance, minBalance;
    Account* account;

    cout << "\n\nPlease enter client name: ";   cin >> name;
    cout << "Please enter client address: ";   cin >> address;
    cout << "Please enter client phone: ";   cin >> phone;
    cout << "What Type of Account Do You Like?\n\t(1) Basic \n\t(2) Saving\n";   cin >> accountType;
    Client client(name, address, phone);


    switch(accountType){
        case 1:
            /** Create Basic account **/
            account = new BankAccount;

            cout << "Please Enter the Starting Balance: " ; cin >> initBalance;
            account->setBalance(initBalance);
            account->setAccountID("FCI-" + intToString(clients.size()+1));
            client.setAccount(account);
            clients.push_back(client);

            cout << "\n===============================================================================================================\n"<< endl;
            cout << "An account was created with ID "<< account->getAccountID() << " and Starting Balance " << initBalance << " L.E." << endl;
            cout << "\n===============================================================================================================\n"<< endl;
            break;
        case 2:
            /** Create Savings accounts **/
            account = new SavingsBankAccount();

            cout << "Please Enter the Minimum Balance: " ; cin >> minBalance;
            cout << "Please Enter the Starting Balance: " ; cin >> initBalance;
            while (initBalance < minBalance){
                cout << "Initial balance cannot be less than MINIMUM balance!!!"<<endl;
                cout << "Please Enter the Minimum Balance: " ; cin >> minBalance;
                cout << "Please Enter the Starting Balance: " ; cin >> initBalance;
            }
            account->setBalance(initBalance);
            account->setMinBalance(minBalance);
            account->setAccountID("FCI-" + intToString(clients.size()+1));
            client.setAccount(account);
            clients.push_back(client);

            cout << "==============================================================================================================="<< endl;
            cout << "An account was created with ID "<< account->getAccountID() << " and Starting Balance " << initBalance << " L.E." << endl;
            cout << "==============================================================================================================="<< endl;
            break;
        default:
            cout << "Invalid account type!!!" << endl;
    }
}

/*************************************************************************/
/** Display all accounts in DB **/
void listAllAccounts(){
    cout << "\n===============================================================================================================\n"<< endl;
    for (unsigned int i=0; i < clients.size(); i++){
        cout << clients.at(i) << endl;
    }
    cout << "\n===============================================================================================================\n"<< endl;
}

/*************************************************************************/
/** Perform Withdraw on an account **/
void wihdrawMoney(){
    string id;
    double amount;
    cout << "\n===============================================================================================================\n"<< endl;

    cout << "Please Enter Account ID (e.g., FCI-015): "; cin >> id;
    for (unsigned int i=0; i < clients.size(); i++){
        if (clients.at(i).getAccount()->getAccountID() == id){
            Account* account = clients.at(i).getAccount();
            cout << "Account ID: " << account->getAccountID() << endl;
            cout << "Account Type: " << account->getType() << endl;
            cout << "Balance: " << account->getBalance() << endl;
            cout << "Please Enter The Amount to Withdraw: " ; cin >> amount;
            while (!account->withdraw(amount)){
                cout << "Sorry. This is more than what you can withdraw." <<endl;
                cout << "Please Enter The Amount to Withdraw: " ; cin >> amount;
            }
            cout << "Thank You." <<endl;
            cout << "Account ID: " << account->getAccountID() << endl;
            cout << "New Balance: " << account->getBalance() << endl;
            cout << "\n===============================================================================================================\n"<< endl;

        }
    }
}
/*************************************************************************/
/** Perform Deposit on an account **/
void depositMoney(){
    string id;
    double amount;
    cout << "\n===============================================================================================================\n"<< endl;

    cout << "Please Enter Account ID (e.g., FCI-015): "; cin >> id;

    for (unsigned int i=0; i < clients.size(); i++){
        if (clients.at(i).getAccount()->getAccountID() == id){
            Account* account = clients.at(i).getAccount();
            cout << "Account ID: " << account->getAccountID() << endl;
            cout << "Account Type: " << account->getType() << endl;
            cout << "Balance: " << account->getBalance() << endl;
            cout << "Please Enter The Amount to Deposit: " ; cin >> amount;

            while (!account->deposit(amount)){
                cout << "Sorry. You cannot deposit this amount of money" <<endl;
                cout << "Please Enter The Amount to Deposit: " ; cin >> amount;
            }
            cout << "Thank You." <<endl;
            cout << "Account ID: " << account->getAccountID() << endl;
            cout << "New Balance: " << account->getBalance() << endl;
            cout << "\n===============================================================================================================\n"<< endl;

        }
    }
}


string intToString(int x){
    ostringstream ss;
    ss << x;
    return ss.str();
}
