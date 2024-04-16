//
//  main.cpp
//  Lab 1
//
//  Created by Taanish Patel on 2/15/24.
//

#include <iostream>
#include <vector>
#include <typeinfo> t
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main() {
    vector<Account*> accounts;

    accounts.push_back(new CheckingAccount(1000.0, 2.0));
    accounts.push_back(new SavingsAccount(1500.0, 0.05));

    int choice;
    cout << "Select an account (0 for CheckingAccount, 1 for SavingsAccount): ";
    cin >> choice;

    while (choice >= 0 && choice < accounts.size()) {
        if (CheckingAccount* checkingAccount = dynamic_cast<CheckingAccount*>(accounts[choice])) {
            double amount;
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            checkingAccount->credit(amount);

            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            checkingAccount->debit(amount);

            cout << "Updated CheckingAccount balance: $" << checkingAccount->getBalance() << endl;
        } else if (SavingsAccount* savingsAccount = dynamic_cast<SavingsAccount*>(accounts[choice])) {
            double amount;
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            savingsAccount->credit(amount);

            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            savingsAccount->debit(amount);

            double interest = savingsAccount->calculateInterest();
            savingsAccount->credit(interest);

            cout << "Updated SavingsAccount balance: $" << savingsAccount->getBalance() << endl;
        } else {
            cout << "Invalid choice. Please select a valid account (0 for CheckingAccount, 1 for SavingsAccount): ";
        }

        cout << "Select another account (or enter a negative number to exit): ";
        cin >> choice;
    }

    for (Account* acc : accounts) {
        delete acc;
    }

    return 0;
}
