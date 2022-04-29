//
// Created by letiz on 11/04/2022.
//

#include "gtest/gtest.h"
#include "../Account.h"

TEST(Account, Constructor) {
    float balance = 155.36;
    float bankCredit = 1000;
    auto* a = new Account ("letizia", 0, balance, bankCredit);

    ASSERT_EQ("letizia", a->getOwner());
    ASSERT_EQ(balance, a->getBalance());
    ASSERT_EQ(bankCredit, a->getBankCredit());
    ASSERT_EQ(bankCredit, a->getMaxBankCredit());

    delete a;
}

TEST (Account, TestGetLastTransaction) {
    auto* testing = new Account ("letizia", 0, 100, 100);

    int tot = 5;
    Transaction* transactionTest[tot];
    for (int i = 0; i < tot; i++) {
        transactionTest[i] = new Transaction (testing->getIban(), "nothing->getIban()", "causal", 10,
                                              "X", "X", true);
        testing->addTransaction(*transactionTest[i]); //inserisce in testa senza fare la transazione
    }

    Transaction* operation = testing->getLastTransaction(); //ritorna la transazione in testa alla lista
    ASSERT_EQ(transactionTest[tot-1]->getNumberOperation(), operation->getNumberOperation());
    ASSERT_EQ(transactionTest[tot-1]->getRecipientIban(), operation->getRecipientIban());
    ASSERT_EQ(transactionTest[tot-1]->getSenderIban(), operation->getSenderIban());
    ASSERT_EQ(transactionTest[tot-1]->getTime(), operation->getTime());
    ASSERT_EQ(transactionTest[tot-1]->getDate(), operation->getDate());
    ASSERT_EQ(transactionTest[tot-1]->getAmount(), operation->getAmount());
    ASSERT_EQ(transactionTest[tot-1]->getCausal(), operation->getCausal());
    ASSERT_EQ(transactionTest[tot-1]->isConciliatory(), operation->isConciliatory());

    delete testing;
    for (int i = 0; i< tot; i++)
        delete transactionTest[i];
}

TEST (Account, TestGetOneDayTransaction) {
    auto* testing = new Account ("letizia", 0, 100, 100);

    auto november_ten = Transaction (testing->getIban(), "nothing", "nothing", 50, "10/11/2021");
    testing->addTransaction(november_ten);

    auto october_three = Transaction (testing->getIban(), "nothing", "nothing", 50, "03/10/2021");
    testing->addTransaction(october_three);

    auto second_november_ten = Transaction (testing->getIban(), "nothing", "nothing", 50, "10/11/2021");
    testing->addTransaction(second_november_ten);

    auto september_nineteen = Transaction (testing->getIban(), "nothing", "nothing", 50, "19/09/2021");
    testing->addTransaction(september_nineteen);

    auto second_october_three = Transaction (testing->getIban(), "nothing", "nothing", 50, "03/10/2021");
    testing->addTransaction(second_october_three);

    auto second_september_nineteen = Transaction (testing->getIban(), "nothing", "nothing", 50, "19/09/2021");
    testing->addTransaction(second_september_nineteen);

    auto third_october_three = Transaction (testing->getIban(), "nothing", "nothing", 50, "03/10/2021");
    testing->addTransaction(third_october_three);


    //DATA INESISTENTE
    list<Transaction> inexistent = testing->getOneDayTransaction("01", "12", "2021");
    ASSERT_EQ(inexistent.size(), 0);

    //DATA ESISTENTE
    list<Transaction> test = testing->getOneDayTransaction("03", "10", "2021");
    ASSERT_EQ(test.size(), 3);

    for (const auto& it : test)
        ASSERT_EQ(it.getDate(), "03/10/2021");

    auto it = test.begin();
    ASSERT_EQ(it->getNumberOperation(), third_october_three.getNumberOperation());
    it++;
    ASSERT_EQ(it->getNumberOperation(), second_october_three.getNumberOperation());
    it++;
    ASSERT_EQ(it->getNumberOperation(), october_three.getNumberOperation());

    delete testing;
}

TEST (Account, TestGetIbanTransaction) {
    auto* testing = new Account ("letizia", 0, 100, 100);
    auto* def = new Account ("recipient", 0, 100, 100);

    auto nothing1 = Transaction (testing->getIban(), "nothing", "causal", 50);
    testing->addTransaction(nothing1);

    auto sender1 = Transaction (def->getIban(), testing->getIban(), "cas", 500);
    testing->addTransaction(sender1);

    auto recipient1 = Transaction (testing->getIban(), def->getIban(), "cas", 500);
    testing->addTransaction(recipient1);

    auto recipient2 = Transaction (testing->getIban(), def->getIban(), "cas", 500);
    testing->addTransaction(recipient2);

    auto nothing2 = Transaction (testing->getIban(), "nothing", "causal", 50);
    testing->addTransaction(nothing2);

    auto sender2 = Transaction (def->getIban(), testing->getIban(), "cas", 500);
    testing->addTransaction(sender2);


    //IBAN INESISTENTE
    list<Transaction> inexistent = testing->getIbanTransaction("inexistent");
    ASSERT_EQ(inexistent.size(), 0);


    //IBAN ESISTENTE
    list<Transaction> test = testing->getIbanTransaction(def->getIban());
    ASSERT_EQ(test.size(), 4);

    auto it = test.begin();
    ASSERT_EQ(it->getNumberOperation(), sender2.getNumberOperation());
    ASSERT_EQ(it->getSenderIban(), def->getIban());
    ASSERT_EQ(it->getRecipientIban(), testing->getIban());

    it++;
    ASSERT_EQ(it->getNumberOperation(), recipient2.getNumberOperation());
    ASSERT_EQ(it->getSenderIban(), testing->getIban());
    ASSERT_EQ(it->getRecipientIban(), def->getIban());


    it++;
    ASSERT_EQ(it->getNumberOperation(), recipient1.getNumberOperation());
    ASSERT_EQ(it->getSenderIban(), testing->getIban());
    ASSERT_EQ(it->getRecipientIban(), def->getIban());

    it++;
    ASSERT_EQ(it->getNumberOperation(), sender1.getNumberOperation());
    ASSERT_EQ(it->getSenderIban(), def->getIban());
    ASSERT_EQ(it->getRecipientIban(), testing->getIban());

    delete testing;
    delete def;
}

TEST (Account, TestGetNotConciliatoryTransaction) {
    auto* testing = new Account ("letizia", 0, 100, 100);

    auto c1 = Transaction (testing->getIban(), "rec", "caus", 0 , "X", "X", true);
    testing->addTransaction(c1);

    list<Transaction> empty = testing->getNotConciliatoryTransaction();
    ASSERT_EQ(empty.size(), 0);

    auto nc1 = Transaction (testing->getIban(), "rec", "caus", 0);
    testing->addTransaction(nc1);

    auto nc2 = Transaction (testing->getIban(), "rec", "caus", 0);
    testing->addTransaction(nc2);

    auto nc3 = Transaction (testing->getIban(), "rec", "caus", 0);
    testing->addTransaction(nc3);

    auto c2 = Transaction (testing->getIban(), "rec", "caus", 0 , "X", "X", true);
    testing->addTransaction(c2);

    auto nc4 = Transaction (testing->getIban(), "rec", "caus", 0);
    testing->addTransaction(nc4);

    auto c3 = Transaction (testing->getIban(), "rec", "caus", 0 , "X", "X", true);
    testing->addTransaction(c3);

    list<Transaction> res = testing->getNotConciliatoryTransaction();
    ASSERT_EQ(res.size(), 4);
    for (const auto& it: res)
        ASSERT_FALSE(it.isConciliatory());

    auto it = res.begin();
    ASSERT_EQ(nc4.getNumberOperation(), it->getNumberOperation());
    ASSERT_EQ(nc4.isConciliatory(), it->isConciliatory());

    it++;
    ASSERT_EQ(nc3.getNumberOperation(), it->getNumberOperation());
    ASSERT_EQ(nc3.isConciliatory(), it->isConciliatory());

    it++;
    ASSERT_EQ(nc2.getNumberOperation(), it->getNumberOperation());
    ASSERT_EQ(nc2.isConciliatory(), it->isConciliatory());

    it++;
    ASSERT_EQ(nc1.getNumberOperation(), it->getNumberOperation());
    ASSERT_EQ(nc1.isConciliatory(), it->isConciliatory());

    delete testing;
}



TEST (Account, TestAddTransaction) {
    auto* a = new Account ("letizia", 0, 100, 100);
    auto* b = new Account ("francesco", 0, 100, 100);

    auto* t = new Transaction (a->getIban(), b->getIban(), "causale" , 50, "03/10/2021", "15:20", true);

    a->addTransaction(*t);
    b->addTransaction(*t, "in");

    ASSERT_EQ(a->sizeHistoricalTransaction(), 1);
    ASSERT_EQ(a->getLastTransaction()->getNumberOperation(), t->getNumberOperation());

    ASSERT_EQ(b->sizeHistoricalTransaction(), 1);
    ASSERT_EQ(b->getLastTransaction()->getNumberOperation(), t->getNumberOperation());

    delete a;
    delete b;
}

TEST (Account, TestRemoveTransaction) {
    auto* testing = new Account ("letizia", 0, 100, 100);

    int tot = 5;
    Transaction* transactionTest[tot];
    for (int i = 0; i < tot; i++) {
        transactionTest[i] = new Transaction (testing->getIban(), "nothing->getIban()", "causal", 50,
                "X", "X", true);
        testing->addTransaction(*transactionTest[i]);
    }
    ASSERT_EQ(testing->sizeHistoricalTransaction(), tot);

    ASSERT_TRUE(testing->removeTransaction(*transactionTest[2]));

    ASSERT_TRUE(testing->removeTransaction(*transactionTest[1]));

    ASSERT_FALSE(testing->removeTransaction(*transactionTest[2]));


    ASSERT_EQ(testing->sizeHistoricalTransaction(), tot-2);
    ASSERT_EQ(testing->getLastTransaction()->getNumberOperation(), transactionTest[4]->getNumberOperation());

    testing->removeTransaction(*transactionTest[4]);
    ASSERT_EQ(testing->getLastTransaction()->getNumberOperation(), transactionTest[3]->getNumberOperation());

    delete testing;
    for (int i = 0; i < tot; i++)
        delete transactionTest[i];
}

TEST (Account, TestSizeHistoricalTransaction) {
    auto* a = new Account ("letizia", 0, 100, 100);

    int size_a = a->sizeHistoricalTransaction();
    ASSERT_EQ(size_a, 0);

    int tot = 10;
    Transaction* transactionTest[tot];
    for (int i = 0; i < tot; i++) {
        transactionTest[i] = new Transaction (a->getIban(), "nothing->getIban()", "causal", 50,
                                              "X", "X", true);
        a->addTransaction(*transactionTest[i]);
    }

    size_a = a->sizeHistoricalTransaction();
    ASSERT_EQ(size_a, tot);

    delete a;
}



TEST (Account, TestReadFile) {
    auto* accountTest = new Account ("letizia", 0, 100, 100);
    float balance = accountTest->getBalance();
    float bankCredit = accountTest->getBankCredit();
    string IBAN = accountTest->getIban();
    string owner = accountTest->getOwner();

    float amount = 50;
    auto transactionTest = Transaction ("b->getIban()" , accountTest->getIban(), "causale" , amount, "X", "X", true);

    balance += amount;


    accountTest->addTransaction(transactionTest,"in");
    accountTest->readFile();

    ASSERT_EQ(balance, accountTest->getBalance());
    ASSERT_EQ(bankCredit, accountTest->getBankCredit());
    ASSERT_EQ(IBAN, accountTest->getIban());
    ASSERT_EQ(owner, accountTest->getOwner());

    delete accountTest;
}
