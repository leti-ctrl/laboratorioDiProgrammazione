//
// Created by letiz on 06/04/2022.
//

#include "Transaction.h"

#include <utility>
#include <ctime>
#include <chrono>


using namespace std;

Transaction::Transaction(string IBAN, string causal, float amount, const string& dateAndTime, bool conciliatory) :
IBAN(move(IBAN)), causal(move(causal)), amount(amount){

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

const string &Transaction::getIban() const {
    return IBAN;
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

bool Transaction::setIban(const string &i) {
    if (conciliatory){
        IBAN = i;
        return true;
    }
    return false;
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
