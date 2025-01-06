#include "../headers/Account.h"

void Account::setBalance(){

}
        
double Account::getBalance() const {
    return balance;
}

double Account::Deposit(double amount){
    if (amount > 0) {
        balance += amount;
        cout<<"Deposited: $"<<amount<<endl;
        log.emplace_back(amount, "Deposit");
    } else{
        cout<<"Invalid deposit amount."<<endl;  
    }
return amount;
}

bool Account::Withdraw(double amount){
    if (amount > balance){
        cout<<"Debit amount exceeded account balance."<<endl;
        return false;
    } else if (amount > 0){
        balance -= amount;
        cout<<"Withdrew: $"<<amount<<endl;
        log.emplace_back(amount, "Withdraw");
        return true;
    } else{
        cout<<"Invalid withdrawal amount."<<endl;
        return false;
    }
}

void Account::report() const {
    cout << "\nTransaction Report:\n";
    for (const auto& transaction : log) {
        cout << transaction.report() << endl;
    }
}

void Account::saveReport(const string& filename) const {
    ofstream outFile(filename);
    if (outFile.is_open()){
        for (const auto& transaction : log) {
            outFile << transaction.report() << endl;
            }
            outFile.close();
            cout << "Transactions saved to " << filename << endl;
    } else {
            cout << "Error opening file for writing." << endl;
    }
}