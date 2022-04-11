//
// Created by letiz on 05/04/2022.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_ACCOUNT_H
#define LABORATORIODIPROGRAMMAZIONE_ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;

static const string TYPE_ACCOUNT [2] = {"Privato", "Aziendale"};

class Account {
public:
    Account (string ow, int typeAccount, float balance, float bankCredit);

    const string &getOwner() const;
    const string &getIban() const;
    float getBalance() const;

    float getBankCredit() const;

    const float getMaxBankCredit() const;

    Transaction getLAstTransaction();

    void outgoingTransaction (Account* recipient, string causal, float amount);
    int doLegalTransaction (float amount);

    void incomingTransaction (Transaction* t);
    int doRefill (float amount);

private:
    string owner;
    string IBAN;
    string numberAccount;
    string typeAccount;
    float balance;
    float bankCredit;
    const float MAX_BANK_CREDIT;
    vector<Transaction> historicalTransaction;

    void writeIncomingTransaction(const Transaction& tr, int refill);
    void writeOutgoingTransaction(const Transaction& tr, int legal);
    void errorTransaction(const Transaction& transaction);
};


#endif //LABORATORIODIPROGRAMMAZIONE_ACCOUNT_H
