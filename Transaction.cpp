//
// Created by letiz on 06/04/2022.
//

#include "Transaction.h"

#include <utility>
#include <ctime>
#include <chrono>


using namespace std;

Transaction::Transaction(string senderIBAN, string recipientIBAN, string causal, float amount, const string& dateAndTime, bool conciliatory) :
senderIBAN(move(senderIBAN)), recipientIBAN(move(recipientIBAN)), causal(move(causal)), amount(amount){

    numberOperation = to_string((rand()%899999)+100000);
    this->conciliatory = conciliatory;

    //data e ora transazione
    if (dateAndTime == " ") {
        time_t now = chrono::system_clock::to_time_t(std::chrono::system_clock::now());

        string s(30, '\0');
        strftime(&s[0], s.size(), "%Y/%m/%d - %H:%M:%S", std::localtime(&now));
        this->dateAndTime = s;
    }
    else
        this->dateAndTime = dateAndTime;
}

float Transaction::getAmount() const {
    return amount;
}

const string &Transaction::getCausal() const {
    return causal;
}

const string &Transaction::getDateAndTime() const {
    return dateAndTime;
}

const string &Transaction::getNumberOperation() const {
    return numberOperation;
}

bool Transaction::isConciliatory() const {
    return conciliatory;
}

bool Transaction::setCausal(const string &c) {
    if (conciliatory){
        causal = c;
        return true;
    }
    return false;
}

bool Transaction::setDateAndTime(const string &det) {
    if (conciliatory){
        dateAndTime = det;
        return true;
    }
    return false;
}

bool Transaction::setAmount(float a) {
    if (conciliatory){
        amount = a;
        return true;
    }
    return false;
}

void Transaction::setConciliatory(bool conc) {
    Transaction::conciliatory = conc;
}

const string &Transaction::getSenderIban() const {
    return senderIBAN;
}

const string &Transaction::getRecipientIban() const {
    return recipientIBAN;
}

void Transaction::setRecipientIban(const string &recipientIban) {
    recipientIBAN = recipientIban;
}
