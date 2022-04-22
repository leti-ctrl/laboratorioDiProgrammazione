//
// Created by letiz on 11/04/2022.
//

#include "gtest/gtest.h"
#include "../Account.h"

class AccountSuite : public ::testing::Test {
protected:
    virtual void SetUp () {
        balance = 123.45;
        bankCredit = 1000;
        a = new Account ("Mario", 0, balance, bankCredit);
        b = new Account ("Luigi", 0, balance, bankCredit);
    }

    Account* a;
    Account* b;
    float balance;
    float bankCredit;
};

TEST_F(AccountSuite, outgoingTransactionTest) {
    float amount = 75.16;
    a->createTransaction(b, " causale ", amount);

    float balanceA = balance - amount;
    ASSERT_EQ(balanceA, a->getBalance());

    float balanceB = balance + amount;
    ASSERT_EQ(balanceB, b->getBalance());
}