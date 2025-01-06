#include "../headers/CheckingAccount.h"

bool CheckingAccount::Withdraw(double amount) {
    if (amount > 0 && amount + transactionFee <= getBalance()) {

        Account::Withdraw(amount);
        double newBal = getBalance() - transactionFee;
        cout << "Transaction fee is $" << transactionFee << endl;
        log.emplace_back(transactionFee, "Transaction Fee");
        cout << "New balance is $" << newBal << endl;
        return true;
    } else {
        cout << "Excess detected." << endl;
        return false;
    }
}