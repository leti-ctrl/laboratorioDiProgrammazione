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
}

TEST(Account, TestDoLegalTransaction) {
    float balance = 155.36;
    float bankCredit = 100;
    auto* a = new Account ("letizia", 0, balance, bankCredit);

    float firstAmount = 75.15;
    float firstRet = balance - firstAmount;
    int zero = a->legalTransaction(firstAmount);
    ASSERT_EQ(0, zero);
    ASSERT_EQ(firstRet, a->getBalance());

    float secondAmount = 100.25;
    float secondRet = (firstRet+bankCredit) - secondAmount;
    int one = a->legalTransaction(secondAmount);
    ASSERT_EQ(1, one);
    ASSERT_EQ(0.0, a->getBalance());
    ASSERT_EQ(secondRet, a->getBankCredit());

    float thirdAmount = 80.00;
    int minusOne = a->legalTransaction(thirdAmount);
    ASSERT_EQ(-1, minusOne);
    ASSERT_EQ(0.0, a->getBalance());
    ASSERT_EQ(secondRet, a->getBankCredit());
}

TEST(Account, TestDoRefill) {
    float balance = 0;
    float bankCredit = 100;
    auto* a = new Account ("letizia", 0, balance, bankCredit);

    float reduceBankCredit = 50;
    a->legalTransaction(reduceBankCredit);
    float result = bankCredit - reduceBankCredit;

    float firstAmount = 35.65;
    float firstResult = result + firstAmount;
    int onlyBankCredit = a->doRefill(firstAmount);
    ASSERT_EQ(1, onlyBankCredit);
    ASSERT_EQ(0, a->getBalance());
    ASSERT_EQ(firstResult, a->getBankCredit());

    float secondAmount = 80.99;
    float secondBankCredit = bankCredit;
    float secondResult = secondAmount - (bankCredit-firstResult);
    int bankCreditAndBalance = a->doRefill(secondAmount);
    ASSERT_EQ(1, bankCreditAndBalance);
    ASSERT_EQ(secondResult, a->getBalance());
    ASSERT_EQ(secondBankCredit, a->getBankCredit());

    float thirdAmount = 20.35;
    float thirdResult = secondResult + thirdAmount;
    int onlyBalance = a->doRefill(thirdAmount);
    ASSERT_EQ(0, onlyBalance);
    ASSERT_EQ(thirdResult, a->getBalance());
}