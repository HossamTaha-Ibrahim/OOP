#include "BankAccount.h"

BankAccount::BankAccount()
{
    balance = 0;
    type = "Basic";
}

BankAccount::BankAccount(double b){
    balance = b;
    type = "Basic";
}

bool BankAccount::withdraw(double amount){
    if (amount > balance){
        return false;
    }
    balance -= amount;
    return true;
}

bool BankAccount::deposit(double amount){
    balance += amount;
    return true;
}
