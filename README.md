### Bank System - README
## Overview
This project is a simple bank system simulation that allows users to manage a Savings Account and a Checking Account. The system supports basic operations such as deposits, withdrawals, and viewing transaction reports. The transactions can also be saved to a file for record-keeping.

## Features
Account Management:

Savings Account: Supports deposits, withdrawals, and interest calculation.
Checking Account: Supports deposits, withdrawals, and includes a transaction fee for withdrawals.
Transaction Reporting:

View a detailed report of all transactions for both Savings and Checking Accounts.
Save transaction reports to text files (savings transactions.txt and checking transactions.txt).
User Interaction:

Interactive menu-driven interface for easy navigation and operation.

## Table of Contents

- [Description](#description)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Description

This project is a simple bank system simulation that allows users to manage a Savings Account and a Checking Account. The system supports basic operations such as deposits, withdrawals, and viewing transaction reports. The transactions can also be saved to a file for record-keeping.

## Requirements

To run this project, you need:

 - A C++ compiler (e.g., GCC, Clang, or MSVC).
 - A terminal or command-line interface.
 - Basic knowledge of C++ programming (to modify).

## Installation

To install the project, follow these steps:
1. Clone the repository using Git: `[https://github.com/jojo6550/Johnson-Commercial-Bank.git]`

2. Navigate to the project directory:
    cd XYZBank

3. Compile code using c++ compiler:
    g++ src/main.cpp src/Account.cpp src/SavingsAccount.cpp src/CheckingAccount.cpp src/Transaction.cpp -o XYZATM    

## Usage

1. Run the compiled code:
    ./XYZATM

2. Follow the on-screen prompts to:
 - Enter initial balances, interest rates, and transaction fees.

 - Perform operations such as deposits, withdrawals, and viewing transaction reports.

 - Save transactions to files for future reference.

## Contributing
Contributions are welcome! If you'd like to contribute:

1. Fork the repository.

2. Create a new branch for your feature or bugfix.

3. Submit a pull request with a detailed description of your changes.

## Liscense

This project is licensed under the MIT License. See the LICENSE file for details.