#pragma once

#include <iostream>
#include <string>
using namespace std;
class Transaction{
    private:
        double amount;
        string type;
    public:
        Transaction(){
            
        }
        Transaction(double amt, string kind){
            amount = amt;
            type = kind;
        }
        string report() const;
};