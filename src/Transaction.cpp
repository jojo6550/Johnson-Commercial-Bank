#include "../headers/Transaction.h"

string Transaction::report() const {
    return "Transaction type: " + type + "\n Amount: " + to_string(amount) + "\n";
}