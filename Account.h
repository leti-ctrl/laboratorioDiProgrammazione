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

    Transaction* getLastTransaction();
    list<Transaction> getOneDayTransaction (const string &day, const string &month, const string &year);
    list<Transaction> getIbanTransaction (const string &iban);
    list<Transaction> getNotConciliatoryTransaction ();

    bool removeTransaction (const Transaction &rem);
    void addTransaction (const Transaction &tr, const string& inOut = "out");
    int sizeHistoricalTransaction ();

    void createTransaction (Account* recipient, string causal, float amount, const string& date = "X",
            const string& time = "X", bool conciliatory = false);
    void createTransaction (Account* recipient, string causal, float amount, bool conciliatory);

    void setConciliatoryAndDoTransaction (Account* rec, Transaction* tr);

    void readFile ();

private:
    string owner;
    string IBAN;
    string numberAccount;
    string typeAccount;
    float balance;
    float bankCredit;
    const float MAX_BANK_CREDIT;
    list<Transaction> historicalTransaction;

    void writeTransaction(const Transaction& tr, const string& inOut = "out");
    void errorTransaction(const Transaction& transaction);

    void doTransaction (Account* recipient, const Transaction& tr);
    int legalTransaction (float amount);
    void doRefill (const Transaction &tr);
};


#endif //LABORATORIODIPROGRAMMAZIONE_ACCOUNT_H
