//
// Created by letiz on 06/04/2022.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_TRANSACTION_H
#define LABORATORIODIPROGRAMMAZIONE_TRANSACTION_H

#include <string>


using namespace std;

class Transaction {
public:
    Transaction (string senderIBAN, string recipientIBAN, string causal, float amount, const string& dateAndTime = "X",
            const string& time = "X", bool concilitory = false);

    float getAmount() const;
    bool setAmount(float a);

    const string &getSenderIban() const;

    const string &getRecipientIban() const;
    void setRecipientIban(const string &recipientIban);

    const string &getCausal() const;
    bool setCausal(const string &c);

    const string &getDate() const;
    bool setDate(const string& day, const string& month, const string& year);

    const string &getTime() const;
    bool setTime(const string &hours, const string &minutes);

    const string &getNumberOperation() const;

    bool isConciliatory() const;
    void setConciliatory();

private:
    string senderIBAN;
    string recipientIBAN;
    string numberOperation;
    string causal;
    string date;
    string time;
    float amount;
    bool conciliatory;
};


#endif //LABORATORIODIPROGRAMMAZIONE_TRANSACTION_H
