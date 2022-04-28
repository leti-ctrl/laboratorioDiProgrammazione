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

    //CREA UNA TRANSAZIONE DA MARIO A LUIGI CON DATA DI SISTEMA E NON CONCILIATA
    float marioLuigi1 = 521.32;
    mario->createTransaction(luigi, "1_ mario -> luigi", marioLuigi1);
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
    ASSERT_EQ(mario->getLastTransaction()->getAmount(), marioLuigi1);

    //FA LA TRANSAZIONE TRA MARIO E LUIGI
    mario->setConciliatoryAndDoTransaction(luigi, mario->getLastTransaction());
    countSizeLuigi++;
    ASSERT_EQ(countSizeMario, mario->sizeHistoricalTransaction());
    ASSERT_EQ(countSizeLuigi, luigi->sizeHistoricalTransaction());
    ASSERT_EQ(mario->getLastTransaction()->isConciliatory(), true);
    ASSERT_EQ(mario->getLastTransaction()->isConciliatory(), luigi->getLastTransaction()->isConciliatory());
    ASSERT_EQ(mario->getLastTransaction()->getNumberOperation(), luigi->getLastTransaction()->getNumberOperation());
    ASSERT_EQ(mario->getLastTransaction()->getRecipientIban(), luigi->getLastTransaction()->getRecipientIban());
    ASSERT_EQ(mario->getLastTransaction()->getSenderIban(), luigi->getLastTransaction()->getSenderIban());
    ASSERT_EQ(mario->getLastTransaction()->getAmount(), luigi->getLastTransaction()->getAmount());
    ASSERT_EQ(mario->getLastTransaction()->getDate(), luigi->getLastTransaction()->getDate());
    ASSERT_EQ(mario->getLastTransaction()->getTime(), luigi->getLastTransaction()->getTime());
    ASSERT_EQ(mario->getLastTransaction()->getCausal(), luigi->getLastTransaction()->getCausal());


    bankCreditMario = bankCreditMario - (marioLuigi1-balanceMario);
    balanceMario = 0;
    balanceLuigi += marioLuigi1;
    ASSERT_EQ(balanceMario, mario->getBalance());
    ASSERT_EQ(bankCreditMario, mario->getBankCredit());
    ASSERT_EQ(balanceLuigi, luigi->getBalance());
    ASSERT_EQ(bankCreditLuigi, luigi->getBankCredit());



    //TRANSAZIONE TRA LUIGI E CARLO CON DATA DI SISTEMA E CONCILIATA
    float luigiCarlo1 = 921.35;
    luigi->createTransaction(carlo, "1_ luigi -> carlo ", luigiCarlo1, true);
    countSizeLuigi++;
    countSizeCarlo++;


    ASSERT_EQ(luigi->sizeHistoricalTransaction(), countSizeLuigi);
    ASSERT_EQ(carlo->sizeHistoricalTransaction(), countSizeCarlo);
    ASSERT_EQ(luigi->getLastTransaction()->getNumberOperation(), carlo->getLastTransaction()->getNumberOperation());
    ASSERT_EQ(luigi->getIban(), luigi->getLastTransaction()->getSenderIban());
    ASSERT_EQ(carlo->getIban(), luigi->getLastTransaction()->getRecipientIban());
    ASSERT_EQ(luigi->getIban(), carlo->getLastTransaction()->getSenderIban());
    ASSERT_EQ(carlo->getIban(), carlo->getLastTransaction()->getRecipientIban());
    ASSERT_EQ(carlo->getLastTransaction()->getAmount(), luigiCarlo1);
    ASSERT_EQ(luigi->getLastTransaction()->getAmount(), luigiCarlo1);
    ASSERT_EQ(carlo->getLastTransaction()->getDate(), luigi->getLastTransaction()->getDate());
    ASSERT_EQ(carlo->getLastTransaction()->getTime(), luigi->getLastTransaction()->getTime());
    ASSERT_EQ(carlo->getLastTransaction()->isConciliatory(), true);
    ASSERT_EQ(luigi->getLastTransaction()->isConciliatory(), true);

    bankCreditLuigi = bankCreditLuigi - (luigiCarlo1 - balanceLuigi);
    balanceLuigi = 0;
    balanceCarlo += luigiCarlo1;
    ASSERT_EQ(balanceLuigi, luigi->getBalance());
    ASSERT_EQ(bankCreditLuigi, luigi->getBankCredit());
    ASSERT_EQ(MAXBankCreditLuigi, luigi->getMaxBankCredit());
    ASSERT_EQ(balanceCarlo, carlo->getBalance());
    ASSERT_EQ(bankCreditCarlo, carlo->getBankCredit());
    ASSERT_EQ(MAXBankCreditCarlo, carlo->getMaxBankCredit());

    //TRANSAZIONE DA CARLO A MARIO CON UNA CON DATA A SCELTA MA NON CONCILIATA
    float carloMario1 = 842.35;
    string dateCarloMario1 = "03/10/2021";

    carlo->createTransaction(mario, "1_ carlo -> mario", carloMario1, dateCarloMario1);
    countSizeCarlo++;
    ASSERT_EQ(countSizeCarlo, carlo->sizeHistoricalTransaction());
    ASSERT_EQ(countSizeMario, mario->sizeHistoricalTransaction());
    ASSERT_EQ(balanceCarlo, carlo->getBalance());
    ASSERT_EQ(balanceMario, mario->getBalance());

    //PROVO A FARE LA TRANSAZIONE MA PASSANDO UNA TRANSAZIONE SBAGLIATA
    Transaction* carloLast = carlo->getLastTransaction();
    carloLast->setConciliatory();
    carlo->setConciliatoryAndDoTransaction(mario,luigi->getLastTransaction());
    ASSERT_EQ(countSizeCarlo, carlo->sizeHistoricalTransaction());
    ASSERT_EQ(countSizeMario, mario->sizeHistoricalTransaction());
    ASSERT_EQ(countSizeLuigi, luigi->sizeHistoricalTransaction());
    ASSERT_EQ(balanceCarlo, carlo->getBalance());
    ASSERT_EQ(balanceMario, mario->getBalance());
    ASSERT_EQ(balanceLuigi, luigi->getBalance());


}