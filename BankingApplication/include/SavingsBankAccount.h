#ifndef SAVINGSBANKACCOUNT_H
#define SAVINGSBANKACCOUNT_H
#include "Account.h"
#include <iostream>
using namespace std;

class SavingsBankAccount : public Account
{
    private:
        double minimumBalance;


    public:
        SavingsBankAccount();
        SavingsBankAccount(double, double);

        void setMinBalance(double);
        double getMinBalance();

        bool withdraw(double);
        bool deposit(double);


};

#endif // SAVINGSBANKACCOUNT_H
