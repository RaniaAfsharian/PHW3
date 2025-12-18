#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <vector>
#include "Customer.h"
#include "Transaction.h"

class BankSystem {
private:
    std::vector<Customer> allCustomers;
    std::vector<Transaction> allTransactions;

public:
    BankSystem();
    void addNewCustomer(const Customer& customer);
    void addTransaction(const Transaction& trans);
    Customer* searchCustomerById(int id);
    void showFullSystemReport() const;
};

#endif