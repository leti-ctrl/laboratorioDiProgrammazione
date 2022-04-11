//
// Created by letiz on 06/04/2022.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_TRANSACTION_H
#define LABORATORIODIPROGRAMMAZIONE_TRANSACTION_H

#include <string>

using namespace std;

class Transaction {
public:
    Transaction (string sender, string nameRecipient, string IBANrecipient, string causal, float amount);

    float getAmount() const;
    const string &getSender() const;
    const string &getNameRecipient() const;
    const string &getIbanRecipient() const;
    const string &getCausal() const;
    const string &getDateAndTime() const;
    const string &getNumberOperation() const;

private:
    string sender;
    string nameRecipient;
    string IBANrecipient;
    string numberOperation;
    string causal;
    string dateAndTime;
    float amount;
};


#endif //LABORATORIODIPROGRAMMAZIONE_TRANSACTION_H
