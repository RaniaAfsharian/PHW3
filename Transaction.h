#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

class Transaction {
public:
    enum Type { DEPOSIT, WITHDRAWAL, TRANSFER };

private:
    int transactionId;
    Type transactionType;
    double transactionAmount;
    std::string transactionDateTime;  
    static int nextTransactionId;

public:
    Transaction(Type t, double amount);
    void display() const;
    
    bool operator==(const Transaction& other) const;
    
    Transaction operator+(const Transaction& other) const;
    
    int getId() const;
    double getAmount() const;
};

#endif