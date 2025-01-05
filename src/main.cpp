#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
        string report() const {
            return "Transaction type: " + type + "\n Amount: " + to_string(amount) + "\n";
        }
};
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
        //not sure what this should do in the programme but its here.
        void setBalance(){

        }

        double getBalance()const{
            return balance;
        }

        double Deposit(double amount){
            if (amount > 0) {
                balance += amount;
                cout<<"Deposited: $"<<amount<<endl;
                log.emplace_back(amount, "Deposit");
            } else{
                cout<<"Invalid deposit amount."<<endl;
            }
            return amount;
        }

        bool Withdraw(double amount){
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
        void report() const {
            cout << "\nTransaction Report:\n";
            for (const auto& transaction : log) {
                cout << transaction.report() << endl;
            }
        }
        void saveReport(const string& filename) const {
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
        
};

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

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(double init_bal, double tran_fee) : Account(init_bal), transactionFee(tran_fee) {}

bool Withdraw(double amount) {
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
};

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