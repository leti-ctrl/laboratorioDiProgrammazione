//
// Created by letiz on 05/04/2022.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_ACCOUNT_H
#define LABORATORIODIPROGRAMMAZIONE_ACCOUNT_H

#include <string>
#include <list>
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
    float getMaxBankCredit() const;

    Transaction getLastTransaction();
    list<Transaction> getOneDayTransaction (const string &day, const string &month, const string &year);
    list<Transaction> getIbanTransaction (const string &iban);
    list<Transaction> getNotConciliatoryTransaction ();

    bool removeTransaction (const Transaction &rem);
    void addTransaction (const Transaction &tr);
    int sizeHistoricalTransaction ();

    void outgoingTransaction (Account* recipient, string causal, float amount);
    void incomingTransaction (Transaction* t);

private:
    string owner;
    string IBAN;
    string numberAccount;
    string typeAccount;
    float balance;
    float bankCredit;
    const float MAX_BANK_CREDIT;
    list<Transaction> historicalTransaction;

    void writeIncomingTransaction(const Transaction& tr, int refill);
    void writeOutgoingTransaction(const Transaction& tr, int legal);
    void errorTransaction(const Transaction& transaction);

    int doLegalTransaction (float amount);
    int doRefill (float amount);
};


#endif //LABORATORIODIPROGRAMMAZIONE_ACCOUNT_H
