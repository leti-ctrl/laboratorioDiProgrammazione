//
// Created by letiz on 05/04/2022.
//

#include "Account.h"
#include "Transaction.h"


#include <cstdlib>
#include <utility>
#include <fstream>
#include <ctime>
#include <iostream>

using namespace std;

Account::Account(string ow, int typeAccount, float balance, float bankCredit): owner(move(ow)), typeAccount(TYPE_ACCOUNT[typeAccount]),
balance(balance), bankCredit(bankCredit), MAX_BANK_CREDIT(bankCredit) {

    //genera il numero di conto corrente
    for(int i = 0; i < 4; i++) {
        numberAccount += std::to_string((rand()%899)+100);
    }

    //IBAN
    //due lettere che identificano il paese
    IBAN = "IT";

    //due numeri che indicano il codice interazionale
    IBAN += to_string((rand()%89)+10);

    //una lettera per il contorllo nazionale
    string alphabeth [26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    IBAN += alphabeth[rand()%26];

    //cinque numeri identificativi della banca

    IBAN += to_string((rand()%89999)+10000);

    //cinque numeri identificativi della succursale della banca
    IBAN += to_string((rand()%89999)+10000);

    //numero di conto corrente
    IBAN += numberAccount;

    //giorno di apertura
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"%x",timeinfo);


    //inizializzazione del file di testo
    auto file = new fstream (IBAN, ios::out);
    *file << "####################       Conto corrente numero: " << numberAccount <<"       ####################"<< endl;
    *file << "#   Proprietario: " << owner << endl;
    *file << "#   CC a uso " << this->typeAccount << endl;
    *file << "#   IBAN: " << IBAN << endl;
    *file << "#   Aperto in data " << buffer << endl;
    *file << "#   Fido massimo: " << this->bankCredit << "$" << endl;
    *file << "########################################################################################"<<endl;
    *file << endl;
    file->close();
    delete file;
}

const string &Account::getOwner() const {
    return owner;
}

const string &Account::getIban() const {
    return IBAN;
}

float Account::getBalance() const {
    return balance;
}

void Account::outgoingTransaction(Account *recipient, string causal, float amount) {
    auto* t = new Transaction (owner,recipient->getOwner(), recipient->getIban(), move(causal), amount);
    historicalTransaction.push_back(*t);
    int legal = doLegalTransaction(amount);
    if (legal != -1){
        writeOutgoingTransaction(*t, legal);
        recipient->incomingTransaction(t);
    }
    else {
        errorTransaction(*t);
    }

}

void Account::incomingTransaction(Transaction *t) {
    int refill = doRefill(t->getAmount());
    historicalTransaction.push_back(*t);
    writeIncomingTransaction(*t, refill);
}

void Account::writeIncomingTransaction(const Transaction& tr, int refill) {
    auto file = new fstream (IBAN, ios::app);
    *file << "+++ MOVIMENTO IN ENTRATA " << tr.getDateAndTime() << " -  OPERAZIONE " << tr.getNumberOperation() << endl;
    *file << "    Mittente: " << tr.getSender() << endl;
    *file << "    Causale: " << tr.getCausal() << endl;
    *file << "    Importo: " <<  tr.getAmount() << " $" << endl;
    *file << endl;
    *file << "Saldo: " << balance << " $" << endl;
    if (refill == 1)
        *file << "Fido: " << bankCredit << " $" << endl;
    *file << endl;
    file->close();
    delete(file);
}

void Account::writeOutgoingTransaction(const Transaction& tr, int legal) {
    auto file = new fstream (IBAN, ios::app);
    *file << "--- MOVIMENTO IN USCITA " << tr.getDateAndTime() << " -  OPERAZIONE " << tr.getNumberOperation() << endl;
    *file << "    Destinatario: " << tr.getNameRecipient() << endl;
    *file << "    IBAN: " << tr.getIbanRecipient() << endl;
    *file << "    Causale: " << tr.getCausal() << endl;
    *file << "    Importo: " << tr.getAmount() << " $" << endl;
    *file << endl;
    *file << "Saldo: " << balance << " $" << endl;
    if (legal == 1)
        *file << "Fido: " << bankCredit << " $" << endl;
    *file << endl;
    file->close();
    delete(file);
}

int Account::doLegalTransaction(float amount) {
    //se ritorna 0 c'era abbastanza denaro sul conto
    //se ritorna 1 significa che nel file va inserito anche l'ammontare del FIDO.
    //se ritorna -1 l'operazione non è andata a buon fine
    if (balance >= amount) {
        balance -= amount;
        return 0;
    }
    else if (balance != 0 && bankCredit >= amount-balance) {
        float var = amount - balance;
        balance = 0;
        bankCredit -= var;
        return 1;
    }
    else if (balance == 0 && bankCredit >= amount) {
        bankCredit -= amount;
        return 1;
    }
    else
        return -1;
}


int Account::doRefill(float amount) {
    //ritorna 0 se il fido è massimo e quindi non devo stamparlo
    //ritorna 1 se invece il fido non era massimo e quindi devo stamparlo
    if (bankCredit == MAX_BANK_CREDIT) {
        balance += amount;
        return 0;
    }
    else if (balance == 0 && bankCredit + amount > MAX_BANK_CREDIT) {

        balance += amount - (MAX_BANK_CREDIT - bankCredit);
        bankCredit = MAX_BANK_CREDIT;
        return 1;
    }
    else {
        bankCredit += amount;
        return 1;
    }
}


void Account::errorTransaction(const Transaction& transaction) {
    auto file = new fstream (IBAN, ios::app);
    *file << "[ERRORE] L'OPERAZIONE " << transaction.getNumberOperation() << " NON E' ANDATA A BUON FINE " << endl;
    *file << "[ERRORE] Transazione per " << transaction.getNameRecipient() << " - cod. IBAN: " << transaction.getIbanRecipient() << endl;
    *file << "[ERRORE] Importo " << transaction.getAmount() << "$" << endl;
    *file << endl;
    *file << "Saldo: " << balance << " $" << endl;
    *file << "Fido: " << bankCredit << " $" << endl;
    *file << endl;
    file->close();
    delete(file);
}

Transaction Account::getLAstTransaction() {
    return historicalTransaction.back();
}

float Account::getBankCredit() const {
    return bankCredit;
}

const float Account::getMaxBankCredit() const {
    return MAX_BANK_CREDIT;
}
