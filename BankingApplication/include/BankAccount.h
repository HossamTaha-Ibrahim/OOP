#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "Account.h"
#include <iostream>
using namespace std;

class BankAccount : public Account
{
    public:
        BankAccount();
        BankAccount(double);

        bool withdraw(double);
        bool deposit(double);

};

#endif // BANKACCOUNT_H
