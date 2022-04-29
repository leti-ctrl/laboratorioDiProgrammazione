//
// Created by letiz on 06/04/2022.
//

#include "Transaction.h"

#include <utility>
#include <ctime>
#include <chrono>
#include <iostream>


using namespace std;

Transaction::Transaction(string senderIBAN, string recipientIBAN, string causal, float amount, const string& date,
        const string& time, bool conciliatory) :
        senderIBAN(move(senderIBAN)), recipientIBAN(move(recipientIBAN)), causal(move(causal)), amount(amount){

    numberOperation = to_string((rand()%899999)+100000);
    this->conciliatory = conciliatory;

    //data e ora transazione
    time_t now = chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    if (time == "X"){
        string t(30, '\0');
        strftime(&t[0], t.size(), "%H:%M", std::localtime(&now));
        this->time = t;
    }
    else
        this->time = time;


    if (date == "X") {
        string d(30, '\0');
        strftime(&d[0], d.size(), "%d/%m/%Y", std::localtime(&now));
        this->date = d;
    }
    else
        this->date = date;
}

float Transaction::getAmount() const {
    return amount;
}

const string &Transaction::getCausal() const {
    return causal;
}

const string &Transaction::getNumberOperation() const {
    return numberOperation;
}

bool Transaction::isConciliatory() const {
    return conciliatory;
}

bool Transaction::setCausal(const string &c) {
    if (!conciliatory){
        causal = c;
        return true;
    }
#ifdef _DEBUG
    cerr<<"Non puoi modificare la causale di una transazione conciliata"<< endl;
#endif
    return false;
}

bool Transaction::setAmount(float a) {
    if (!conciliatory){
        amount = a;
        return true;
    }
#ifdef _DEBUG
    cerr<<"Non puoi modificare l'importo di una transazione conciliata"<< endl;
#endif
    return false;
}

void Transaction::setConciliatory() {
    conciliatory = true;
}

const string &Transaction::getSenderIban() const {
    return senderIBAN;
}

const string &Transaction::getRecipientIban() const {
    return recipientIBAN;
}

bool Transaction::setRecipientIban(const string &recipientIban) {
    if (!conciliatory){
        recipientIBAN = recipientIban;
        return true;
    }
#ifdef _DEBUG
    cerr<<"Non puoi modificare il destinatario di una transazione conciliata"<< endl;
#endif
    return false;
}

const string &Transaction::getDate() const {
    return date;
}

bool Transaction::setDate(const string &day, const string &month, const string &year) {
    if (!conciliatory){
        date = day + "/" + month + "/" + year;
        return true;
    }
#ifdef _DEBUG
    cerr<<"Non puoi modificare la data di una transazione conciliata"<< endl;
#endif
    return false;
}

const string &Transaction::getTime() const {
    return time;
}

bool Transaction::setTime(const string &hours, const string &minutes) {
    if (!conciliatory) {
        time = hours + ":" + minutes;
        return true;
    }
#ifdef _DEBUG
    cerr<<"Non puoi modificare l'ora di una transazione conciliata"<< endl;
#endif
    return false;
}
