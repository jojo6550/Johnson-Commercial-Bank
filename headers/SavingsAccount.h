#pragma once
#include "../headers/Account.h"
class SavingsAccount:public Account{
    private:
        float interestRate;
    public:
        SavingsAccount(){
            
        }
        SavingsAccount(double init_bal, float rate):Account(init_bal), interestRate(rate){
        }
        double calcInterest(){
            return interestRate = (interestRate/100) * getBalance();
        }
};