#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../headers/Transaction.h"
#include "../headers/Account.h"
#include "../headers/SavingsAccount.h"
#include "../headers/CheckingAccount.h"
using namespace std;

int main() {
    double initial_balance;
    double interest_rate;
    double transaction_fee;

    try {
        cout << "Enter initial balance for both Accounts: $";
        cin >> initial_balance;
        cout << "Enter interest rate for Savings Account (%): ";
        cin >> interest_rate;
        cout << "Enter transaction fee for Checking Account: $";
        cin >> transaction_fee;

        SavingsAccount savings(initial_balance, interest_rate);
        CheckingAccount checking(initial_balance, transaction_fee);

        int choice = 0;
        double amount;

        cout << "\nXYZATM Menu:" << endl;
        cout << "1. Check Savings Balance" << endl;
        cout << "2. Deposit to Savings" << endl;
        cout << "3. Withdraw from Savings" << endl;
        cout << "4. Withdraw from Checking" << endl;
        cout << "5. View Transaction Report" << endl;
        cout << "6. Save Transactions to File" << endl;
        cout << "7. Exit" << endl;

        while (true) {
            cout << "Choose an option (1-7): ";
            cin >> choice;

            if (choice == 7) {
                cout << "Exiting the program." << endl;
                break;
            }

            switch (choice) {
                case 1:
                    cout << "Savings Account Balance: $" << savings.getBalance() << endl;
                    cout << "Checking Account Balance: $" << checking.getBalance() << endl;
                    break;
                case 2:
                    cout << "Enter amount to deposit to Savings: $";
                    cin >> amount;
                    savings.Deposit(amount);
                    break;
                case 3:
                    cout << "Enter amount to withdraw from Savings: $";
                    cin >> amount;
                    if (savings.Withdraw(amount)) {
                        double interest = savings.calcInterest();
                        savings.Deposit(interest);
                        cout << "Interest added: $" << interest << endl;
                    }
                    break;
                case 4:
                    cout << "Enter amount to withdraw from Checking: $";
                    cin >> amount;
                    checking.Withdraw(amount);
                    break;
                case 5:
                    savings.report();
                    checking.report();
                    break;
                case 6:
                    savings.saveReport("savings transactions.txt");
                    checking.saveReport("checking transactions.txt");
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }

    return 0;
}