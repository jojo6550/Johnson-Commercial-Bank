#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../headers/Transaction.h"
using namespace std;

class Account{
    protected:
        double balance;
        vector<Transaction> log;
    public:
        Account(){
        }
        Account(double init_bal){
            if (init_bal >= 1000.00) {
                balance = init_bal;
            } else {
                balance = 0.0;
                cout<<"Warning: Initial balance is invalid. Balance set to $0.00."<<endl;
            }
        }
        void setBalance();
        
        double getBalance() const;

        double Deposit(double amount);

        bool Withdraw(double amount);

        void report() const;

        void saveReport(const string& filename) const;
};