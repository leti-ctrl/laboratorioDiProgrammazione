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

float Account::getBankCredit() const {
    return bankCredit;
}

float Account::getMaxBankCredit() const {
    return MAX_BANK_CREDIT;
}

Transaction* Account::getLastTransaction() {
    return &(historicalTransaction.front());
}

list<Transaction> Account::getOneDayTransaction(const string &day, const string &month, const string &year) {
    list<Transaction> ret;
    string date = day + "/" + month + "/" + year;
    for (const auto& t : historicalTransaction) {
        if (t.getDate() == date)
            ret.push_back(t);
    }

    if (ret.empty())
        cerr<<"Non sono state fatte transazioni in data " << date << endl;

    return ret;
}

list<Transaction> Account::getIbanTransaction(const string &iban) {
    list<Transaction> ret;

    for (const auto& t : historicalTransaction){
        if (t.getRecipientIban() == iban)
            ret.push_back(t);
        if (t.getSenderIban() == iban)
            ret.push_back(t);
    }

    if (ret.empty())
        cerr<<"Non esistono transazioni da/per questo codice IBAN: " << iban << endl;

    return ret;
}

list<Transaction> Account::getNotConciliatoryTransaction() {
    list<Transaction> ret;

    for (const auto& t : historicalTransaction){
        if (!t.isConciliatory())
            ret.push_back(t);
    }

    if (ret.empty())
        cerr<<"Le transazioni sono tutte conciliate."<<endl;

    return ret;
}

bool Account::removeTransaction(const Transaction &rem) {
    for (auto it = historicalTransaction.begin(); it != historicalTransaction.end(); ++it) {
        if (rem.getNumberOperation() == it->getNumberOperation()){
            historicalTransaction.erase(it);
            return true;
        }
    }

    cerr<<"la transazione numero " << rem.getNumberOperation() << " non è presente. " << endl;
    return false;
}

void Account::addTransaction(const Transaction &tr, const string& inOut) {
    historicalTransaction.push_front(tr);

    if (inOut == "in") {
        doRefill(tr);
    }
}

int Account::sizeHistoricalTransaction() {
    return historicalTransaction.size();
}


void Account::createTransaction(Account *recipient, string causal, float amount, const string& date, const string& time,
                                bool conciliatory) {

    auto t = new Transaction (this->IBAN, recipient->getIban(), std::move(causal), amount, date, time, conciliatory);
    addTransaction(*t);

    if (conciliatory)
        doTransaction(recipient, *t);
    else
        cout<<"Transazione n " << t->getNumberOperation() << " creata ma non conciliata " << endl;
}

void Account::createTransaction(Account *recipient, string causal, float amount, bool conciliatory) {
    auto t = new Transaction (this->IBAN, recipient->getIban(), std::move(causal), amount, "X",
                              "X", conciliatory);
    addTransaction(*t);

    if (conciliatory)
        doTransaction(recipient, *t);
    else
        cout<<"Transazione n " << t->getNumberOperation() << " creata ma non conciliata " << endl;
}

void Account::setConciliatoryAndDoTransaction(Account* rec, Transaction* tr) {

    for (const auto& it : historicalTransaction) {
        if (it.getNumberOperation() == tr->getNumberOperation()) {
            if (rec->getIban() == tr->getRecipientIban()) {
                tr->setConciliatory();
                doTransaction(rec, *tr);
            } else
                cerr << "Il destinatario inserito e quello nella transazione non coincidono. " << endl;
        }
    }
    //cerr << "La transazione cercata non è presente nello storico. " << endl;
}

void Account::writeTransaction(const Transaction& tr, const string& inOut) {

    auto file = new fstream (IBAN, ios::app);

    if (inOut == "in") {
        *file << "+++ MOVIMENTO IN ENTRATA " << tr.getDate() << " " << tr.getTime() << " -  OPERAZIONE "
              << tr.getNumberOperation() << endl;
        *file << "    IBAN: " << tr.getSenderIban() << endl;
    }
    else {
        *file << "--- MOVIMENTO IN USCITA " << tr.getDate() << " " << tr.getTime() << " -  OPERAZIONE "
              << tr.getNumberOperation() << endl;
        *file << "    IBAN: " << tr.getRecipientIban() << endl;
    }

    *file << "    Causale: " << tr.getCausal() << endl;
    *file << "    Importo: " << tr.getAmount() << " $" << endl;
    *file << endl;

    *file << "Saldo: " << balance << " $" << endl;
    *file << "Fido: " << bankCredit << " $" << endl;
    *file << endl;

    file->close();
    delete(file);
}

void Account::errorTransaction(const Transaction& transaction) {
    auto file = new fstream (IBAN, ios::app);

    *file << "[ERRORE] L'OPERAZIONE " << transaction.getNumberOperation() << " NON E' ANDATA A BUON FINE " << endl;
    *file << "[ERRORE] Transazione per cod. IBAN: " << transaction.getRecipientIban() << endl;
    *file << "[ERRORE] Importo " << transaction.getAmount() << "$" << endl;
    *file << endl;

    *file << "Saldo: " << balance << " $" << endl;
    *file << "Fido: " << bankCredit << " $" << endl;
    *file << endl;
    file->close();
    delete(file);
}

int Account::legalTransaction(float amount) {
    //se ritorna 0 c'era abbastanza denaro sul conto
    //se ritorna -1 l'operazione non è andata a buon fine
    if (balance >= amount) {
        balance -= amount;
        return 0;
    }
    else if (balance != 0 && bankCredit >= amount-balance) {
        float var = amount - balance;
        balance = 0;
        bankCredit -= var;
        return 0;
    }
    else if (balance == 0 && bankCredit >= amount) {
        bankCredit -= amount;
        return 0;
    }
    else
        return -1;
}

void Account::doRefill(const Transaction &tr) {
    //ritorna 0 se il fido è massimo e quindi non devo stamparlo
    //ritorna 1 se invece il fido non era massimo e quindi devo stamparlo
    if (bankCredit == MAX_BANK_CREDIT)
        balance += tr.getAmount();

    else if (balance == 0 && bankCredit + tr.getAmount() > MAX_BANK_CREDIT) {
        balance += tr.getAmount() - (MAX_BANK_CREDIT - bankCredit);
        bankCredit = MAX_BANK_CREDIT;
    }
    else
        bankCredit += tr.getAmount();

    writeTransaction(tr, "in");
}


void Account::doTransaction(Account* recipient, const Transaction &tr) {

    int legal = legalTransaction(tr.getAmount());

    if (legal != -1){
        writeTransaction(tr);
        recipient->addTransaction(tr, "in");
    }
    else {
        errorTransaction(tr);
    }
}

void Account::readFile() {
    auto file = new fstream (IBAN, ios::out);
    string line;
    int row = 0;

    while (file->is_open() && file->eof()) {
        getline(*file, line);
        cout << row << " " << line << endl;
    }

    file->close();
    delete file;
}
