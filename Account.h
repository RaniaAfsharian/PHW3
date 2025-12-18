#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

class Account {
public:
    enum Type { SAVINGS, CHECKING, CREDIT };

private:
    int accountId;              
    std::string ownerName;     
    double accountBalance;      
    Type accountType;           
    
    static int nextAvailableId;

public:
    Account(std::string name, double startingMoney, Type typeOfAccount);
    
    void deposit(double moneyToAdd);
    
    void withdraw(double moneyToTake);
    
    void transfer(Account& destinationAccount, double moneyToMove);
    
    void printBalance() const;
    
    int getId() const;
    std::string getOwnerName() const;
    double getBalance() const;
    Type getType() const;
    
    static int getTotalAccountsCreated();
    
    friend std::ostream& operator<<(std::ostream& os, const Account& acc);
};

#endif