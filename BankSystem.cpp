#include "BankSystem.h"
#include "Account.h"
#include <iostream>
#include <iomanip>

BankSystem::BankSystem() {
    std::cout << "Bank system started." << std::endl;
}

void BankSystem::addNewCustomer(const Customer& customer) {
    allCustomers.push_back(customer);
    std::cout << "Customer " << customer.getName() << " added to bank system." << std::endl;
}

void BankSystem::addTransaction(const Transaction& trans) {
    allTransactions.push_back(trans);
    std::cout << "Transaction " << trans.getId() << " recorded." << std::endl;
}

Customer* BankSystem::searchCustomerById(int id) {
    for (int i = 0; i < allCustomers.size(); i++) {
        if (allCustomers[i].getId() == id) {
            return &allCustomers[i];
        }
    }
    return nullptr;
}

void BankSystem::showFullSystemReport() const {
    std::cout << "\n=== BANK SYSTEM REPORT ===" << std::endl;
    std::cout << "Total customers: " << allCustomers.size() << std::endl;
    std::cout << "Total accounts created: " << Account::getTotalAccountsCreated() << std::endl;
    
    double totalMoneyInBank = 0;
    for (int i = 0; i < allCustomers.size(); i++) {
        const std::vector<Account>& accounts = allCustomers[i].getAllAccounts();
        for (int j = 0; j < accounts.size(); j++) {
            totalMoneyInBank += accounts[j].getBalance();
        }
    }
    std::cout << "Total money in all accounts: " 
              << std::fixed << std::setprecision(2) << totalMoneyInBank << std::endl;
    
    std::cout << "\nList of all transactions:" << std::endl;
    if (allTransactions.empty()) {
        std::cout << "  No transactions yet." << std::endl;
    } else {
        for (int i = 0; i < allTransactions.size(); i++) {
            allTransactions[i].display();
        }
    }
    std::cout << "==============================" << std::endl;
}