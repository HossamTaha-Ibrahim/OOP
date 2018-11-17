#include "SavingsBankAccount.h"

SavingsBankAccount::SavingsBankAccount(){
    type = "Savings";
}

/** Parametrized Constructor **/
SavingsBankAccount::SavingsBankAccount(double initBalance, double minBalance){
    type = "Savings";
    if (initBalance >= minBalance){
        balance = initBalance;
        minimumBalance = minBalance;
    }
}
/** Setters **/
void SavingsBankAccount::setMinBalance(double minBalance){
    minimumBalance = minBalance;
}

/** Getters **/
double SavingsBankAccount::getMinBalance(){
    return minimumBalance;
}

/** Withdraw [Amount] from account balance, if there is enough money **/
bool SavingsBankAccount::withdraw(double amount){
    if (balance - amount < minimumBalance){
        return false;
    }
    balance -= amount;
    return true;
}

/** Deposit [Amount] from account balance **/
bool SavingsBankAccount::deposit(double amount){
    if (amount < 100) return false;

    balance += amount;
    return true;
}
