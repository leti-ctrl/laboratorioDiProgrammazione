//
// Created by letiz on 11/04/2022.
//

#include "gtest/gtest.h"
#include "../Account.h"

class AccountSuite : public ::testing::Test {
protected:
    virtual void SetUp () {
        balanceMario = 120.29;
        balanceLuigi = 340.84;
        balanceCarlo = 85.76;

        bankCreditMario = MAXBankCreditMario;
        bankCreditLuigi = MAXBankCreditLuigi;
        bankCreditCarlo = MAXBankCreditCarlo;

        mario = new Account ("Mario", 0, balanceMario, bankCreditMario);
        luigi = new Account ("Luigi", 0, balanceLuigi, bankCreditLuigi);
        carlo = new Account ("Carlo", 1, balanceCarlo, bankCreditCarlo);
    }

    Account* mario;
    Account* luigi;
    Account* carlo;

    float balanceMario;
    float balanceLuigi;
    float balanceCarlo;

    float bankCreditMario;
    float bankCreditLuigi;
    float bankCreditCarlo;

    const float MAXBankCreditMario = 1000;
    const float MAXBankCreditLuigi = 2000;
    const float MAXBankCreditCarlo = 3000;

    int countSizeMario = 0;
    int countSizeLuigi = 0;
    int countSizeCarlo = 0;
};

TEST_F(AccountSuite, createTransactionTest) {

    ASSERT_EQ(mario->getMaxBankCredit(), MAXBankCreditMario);
    ASSERT_EQ(luigi->getMaxBankCredit(), MAXBankCreditLuigi);
    ASSERT_EQ(carlo->getMaxBankCredit(), MAXBankCreditCarlo);

    //CREA UNA TRANSAZIONE DA MARIO A LUIGI MA NON LA FA
    float marioLuigi = 521.32;
    mario->createTransaction(luigi, "mario -> luigi", marioLuigi);
    countSizeMario++;


    ASSERT_EQ(mario->sizeHistoricalTransaction(), countSizeMario);
    ASSERT_EQ(luigi->sizeHistoricalTransaction(), countSizeLuigi);
    ASSERT_EQ(mario->getBalance(), balanceMario);
    ASSERT_EQ(luigi->getBalance(), balanceLuigi);

    //PROVA A FARE LA TRANSAZIONE TRA MARIO E LUIGI MA PASSA L'ACCOUNT DI CARLO
    mario->setConciliatoryAndDoTransaction(carlo, mario->getLastTransaction());
    ASSERT_EQ(balanceCarlo, carlo->getBalance());
    ASSERT_EQ(balanceLuigi, luigi->getBalance());
    ASSERT_EQ(balanceMario, mario->getBalance());
    ASSERT_EQ(mario->sizeHistoricalTransaction(), countSizeMario);
    ASSERT_EQ(luigi->sizeHistoricalTransaction(), countSizeLuigi);
    ASSERT_EQ(carlo->sizeHistoricalTransaction(), countSizeCarlo);
    ASSERT_EQ(mario->getLastTransaction()->isConciliatory(), false);
    ASSERT_EQ(mario->getLastTransaction()->getRecipientIban(), luigi->getIban());
    ASSERT_EQ(mario->getLastTransaction()->getSenderIban(), mario->getIban());
    ASSERT_EQ(mario->getLastTransaction()->getAmount(), marioLuigi);

    //FA LA TRANSAZIONE TRA MARIO E LUIGI
    mario->setConciliatoryAndDoTransaction(luigi, mario->getLastTransaction());
    ASSERT_EQ(mario->getLastTransaction()->isConciliatory(), true);

    bankCreditMario = bankCreditMario - (marioLuigi-balanceMario);
    balanceMario = 0;
    ASSERT_EQ(balanceMario, mario->getBalance());
    ASSERT_EQ(bankCreditMario, mario->getBankCredit());
    ASSERT_EQ(countSizeMario, mario->sizeHistoricalTransaction());


    balanceLuigi += marioLuigi;
    countSizeLuigi++;
    ASSERT_EQ(balanceLuigi, luigi->getBalance());
    ASSERT_EQ(bankCreditLuigi, luigi->getBankCredit());
    ASSERT_EQ(countSizeLuigi, luigi->sizeHistoricalTransaction());



}