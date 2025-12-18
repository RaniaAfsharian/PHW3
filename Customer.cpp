#include "Customer.h"
#include <iostream>

int Customer::nextCustomerId = 0;

Customer::Customer(std::string name) {
    customerName = name;
    customerId = ++nextCustomerId;
    std::cout << "New customer created: " << customerName 
              << " with ID " << customerId << "." << std::endl;
}

void Customer::addAccount(const Account& newAccount) {
    listOfAccounts.push_back(newAccount);
    std::cout << "Account " << newAccount.getId() 
              << " has been added to customer " << customerName << "." << std::endl;
}

void Customer::printAllAccountBalances() const {
    std::cout << "Accounts belonging to " << customerName << ":" << std::endl;
    
    if (listOfAccounts.empty()) {
        std::cout << "  This customer has no accounts yet." << std::endl;
        return;
    }
    
    for (int i = 0; i < listOfAccounts.size(); i++) {
        listOfAccounts[i].printBalance();
    }
}

void Customer::printFullCustomerReport() const {
    std::cout << "\n=== Customer Report ===" << std::endl;
    std::cout << "Customer ID: " << customerId << std::endl;
    std::cout << "Customer Name: " << customerName << std::endl;
    printAllAccountBalances();
    std::cout << "======================" << std::endl;
}

Account* Customer::findAccountById(int accountId) {
    for (int i = 0; i < listOfAccounts.size(); i++) {
        if (listOfAccounts[i].getId() == accountId) {
            return &listOfAccounts[i];
        }
    }
    return nullptr; 
}

int Customer::getId() const { return customerId; }
std::string Customer::getName() const { return customerName; }
const std::vector<Account>& Customer::getAllAccounts() const { return listOfAccounts; }