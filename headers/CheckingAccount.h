#pragma once
#include "../headers/Account.h"
#include <iostream>
#include <vector>

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(double init_bal, double tran_fee) : Account(init_bal), transactionFee(tran_fee) {}

    bool Withdraw(double amount);
};