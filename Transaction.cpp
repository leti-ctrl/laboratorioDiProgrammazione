//
// Created by letiz on 06/04/2022.
//

#include "Transaction.h"

#include <utility>
#include <ctime>

using namespace std;

Transaction::Transaction(string sender, string nameRecipient, string IBANrecipient, string causal, float amount) :
sender(move(sender)), nameRecipient(move(nameRecipient)), IBANrecipient(move(IBANrecipient)), causal(move(causal)),
amount(amount){

    numberOperation = to_string((rand()%899999)+100000);

    //data e ora trasnazione
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"il giorno %x alle ore %X",timeinfo);
    dateAndTime = buffer;
}

float Transaction::getAmount() const {
    return amount;
}

const string &Transaction::getSender() const {
    return sender;
}

const string &Transaction::getNameRecipient() const {
    return nameRecipient;
}

const string &Transaction::getIbanRecipient() const {
    return IBANrecipient;
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
