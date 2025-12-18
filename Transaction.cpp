#include "Transaction.h"
#include <iostream>
#include <iomanip>
#include <ctime>

int Transaction::nextTransactionId = 0;


Transaction::Transaction(Type t, double amount) {
    transactionType = t;
    transactionAmount = amount;
    transactionId = ++nextTransactionId;

    time_t now = time(0);
    tm* local = localtime(&now);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", local);
    transactionDateTime = buf;
}

void Transaction::display() const {
    std::cout << "Transaction ID: " << transactionId << " | Type: ";
    
    if (transactionType == DEPOSIT) {
        std::cout << "Deposit";
    } else if (transactionType == WITHDRAWAL) {
        std::cout << "Withdrawal";
    } else if (transactionType == TRANSFER) {
        std::cout << "Transfer";
    }
    
    std::cout << " | Amount: " << transactionAmount
              << " | Date/Time: " << transactionDateTime << std::endl;
}

bool Transaction::operator==(const Transaction& other) const {
    if (transactionId != other.transactionId) return false;
    if (transactionType != other.transactionType) return false;
    if (transactionAmount != other.transactionAmount) return false;
    return true;
}



Transaction Transaction::operator+(const Transaction& other) const {
    double newAmount = transactionAmount + other.transactionAmount;
    return Transaction(DEPOSIT, newAmount);  
}

int Transaction::getId() const { 
    return transactionId; 
}

double Transaction::getAmount() const { 
    return transactionAmount; 
}