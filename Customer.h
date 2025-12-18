#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Account.h"

class Customer {
private:
    int customerId;
    std::string customerName;
    std::vector<Account> listOfAccounts;
    static int nextCustomerId;

public:
    Customer(std::string name);
    void addAccount(const Account& newAccount);
    void printAllAccountBalances() const;
    void printFullCustomerReport() const;
    
    Account* findAccountById(int accountId);
    
    int getId() const;
    std::string getName() const;
    const std::vector<Account>& getAllAccounts() const;
};

#endif