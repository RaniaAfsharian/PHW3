#include "Account.h"
#include <iostream>
#include <iomanip>

int Account::nextAvailableId = 0;

int Account::getTotalAccountsCreated() {
    return nextAvailableId;
}

Account::Account(std::string name, double startingMoney, Type typeOfAccount) {
    ownerName = name;
    accountBalance = startingMoney;
    accountType = typeOfAccount;
    
    accountId = ++nextAvailableId;
    
    std::cout << "New account created for " << ownerName 
              << " with ID " << accountId << "." << std::endl;
}

void Account::deposit(double moneyToAdd) {
    if (moneyToAdd > 0) {
        accountBalance = accountBalance + moneyToAdd;
        std::cout << "Deposited " << moneyToAdd << " to account " << accountId 
                  << ". New balance: " << std::fixed << std::setprecision(2) 
                  << accountBalance << std::endl;
    } else {
        std::cout << "Error: Deposit amount must be greater than zero." << std::endl;
    }
}

void Account::withdraw(double moneyToTake) {
    if (accountType == SAVINGS) {
        if (accountBalance - moneyToTake < 100) {
            std::cout << "Withdrawal failed: Savings account cannot go below 100." << std::endl;
            return;
        }
    }
    
    if (moneyToTake > 0) {
        if (accountBalance >= moneyToTake) {
            accountBalance = accountBalance - moneyToTake;
            std::cout << "Withdrew " << moneyToTake << " from account " << accountId 
                      << ". New balance: " << std::fixed << std::setprecision(2) 
                      << accountBalance << std::endl;
        } else {
            std::cout << "Withdrawal failed: Not enough money in account." << std::endl;
        }
    } else {
        std::cout << "Error: Withdrawal amount must be greater than zero." << std::endl;
    }
}

void Account::transfer(Account& destinationAccount, double moneyToMove) {
    if (moneyToMove > 0 && accountBalance >= moneyToMove) {
        accountBalance = accountBalance - moneyToMove;
        
        destinationAccount.accountBalance = destinationAccount.accountBalance + moneyToMove;
        
        std::cout << "Transferred " << moneyToMove << " from account " << accountId 
                  << " to account " << destinationAccount.accountId << "." << std::endl;
    } else if (moneyToMove <= 0) {
        std::cout << "Error: Transfer amount must be greater than zero." << std::endl;
    } else {
        std::cout << "Transfer failed: Not enough money in source account." << std::endl;
    }
}


void Account::printBalance() const {
    std::cout << "Account ID: " << accountId 
              << ", Owner: " << ownerName 
              << ", Balance: " << accountBalance 
              << ", Type: ";
    
    if (accountType == SAVINGS) {
        std::cout << "Savings";
    } else if (accountType == CHECKING) {
        std::cout << "Checking";
    } else if (accountType == CREDIT) {
        std::cout << "Credit";
    }
    
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Account& acc) {
    os << "ID: " << acc.accountId << " | Owner: " << acc.ownerName 
       << " | Balance: " << acc.accountBalance 
       << " | Type: ";
    
    if (acc.accountType == Account::SAVINGS) os << "Savings";
    else if (acc.accountType == Account::CHECKING) os << "Checking";
    else os << "Credit";
    
    return os;
}