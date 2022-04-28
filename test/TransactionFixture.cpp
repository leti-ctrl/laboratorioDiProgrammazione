//
// Created by letiz on 28/04/2022.
//

#include "gtest/gtest.h"
#include "../Transaction.h"

TEST (Transaction, Constructor) {
    string sender = "sender";
    string recipient = "recipient";
    string causal = "causal";
    float amount = 133.15;

    Transaction testFirst = Transaction (sender, recipient, causal, amount);
    ASSERT_EQ(testFirst.getSenderIban(), sender);
    ASSERT_EQ(testFirst.getRecipientIban(), recipient);
    ASSERT_EQ(testFirst.getCausal(), causal);
    ASSERT_EQ(testFirst.getAmount(), amount);
    ASSERT_EQ(testFirst.isConciliatory(), false);

    string date = "05/04/2021";
    Transaction testSecond = Transaction (sender, recipient, causal, amount, date);
    ASSERT_EQ(testSecond.getSenderIban(), sender);
    ASSERT_EQ(testSecond.getRecipientIban(), recipient);
    ASSERT_EQ(testSecond.getCausal(), causal);
    ASSERT_EQ(testSecond.getAmount(), amount);
    ASSERT_EQ(testSecond.getDate(), date);
    ASSERT_EQ(testSecond.isConciliatory(), false);

    string time = "15:11";
    Transaction testThird = Transaction (sender, recipient, causal, amount, date, time);
    ASSERT_EQ(testThird.getSenderIban(), sender);
    ASSERT_EQ(testThird.getRecipientIban(), recipient);
    ASSERT_EQ(testThird.getCausal(), causal);
    ASSERT_EQ(testThird.getAmount(), amount);
    ASSERT_EQ(testThird.getDate(), date);
    ASSERT_EQ(testThird.getTime(), time);
    ASSERT_EQ(testThird.isConciliatory(), false);

    bool conciliatory = true;
    Transaction testFourth = Transaction (sender, recipient, causal, amount, date, time, conciliatory);
    ASSERT_EQ(testFourth.getSenderIban(), sender);
    ASSERT_EQ(testFourth.getRecipientIban(), recipient);
    ASSERT_EQ(testFourth.getCausal(), causal);
    ASSERT_EQ(testFourth.getAmount(), amount);
    ASSERT_EQ(testFourth.getDate(), date);
    ASSERT_EQ(testFourth.getTime(), time);
    ASSERT_EQ(testFourth.isConciliatory(), conciliatory);

}

TEST (Transaction, TestSetAmount) {
    float amount = 865.15;
    float test = 327.23;

    //SETAMOUNT CON CONCILIATORY == TRUE
    auto testing = new Transaction ("sender", "recipient", "causal", amount, "date", "time", true);
    bool res = testing->setAmount(test);
    ASSERT_EQ(testing->getAmount(), amount);
    ASSERT_EQ(res, false);

    //SETAMOUNT CON CONCILIATORY == FALSE;
    auto secondTesting = new Transaction ("sender", "recipient", "causal", amount, "date", "time");
    bool secondRes = secondTesting->setAmount(test);
    ASSERT_EQ(secondTesting->getAmount(), test);
    ASSERT_EQ(secondRes, true);

    delete testing;
    delete secondTesting;
}

TEST (Transaction, TestSetCausal) {
    string causal = "casual";
    string test = "test";

    //SETCAUSAL CON CONCILIATORY == TRUE
    auto testing = new Transaction ("sender", "recipient", causal , 123.4 , "date", "time", true);
    bool res = testing->setCausal(test);
    ASSERT_EQ(testing->getCausal(), causal);
    ASSERT_EQ(res, false);

    //SETCAUSAL CON CONCILIATORY == FALSE;
    auto secondTesting = new Transaction ("sender", "recipient", causal , 123.4 , "date", "time");
    bool secondRes = secondTesting->setCausal(test);
    ASSERT_EQ(secondTesting->getCausal(), test);
    ASSERT_EQ(secondRes, true);

    delete testing;
    delete secondTesting;

}

TEST (Transaction, TestSetRecipientIban) {
    string recipient = "recipient";
    string test = "test";

    //SETRECIPIENT CON CONCILIATORY == TRUE
    auto testing = new Transaction ("sender", recipient, "causal" , 123.4 , "date", "time", true);
    bool res = testing->setRecipientIban(test);
    ASSERT_EQ(testing->getRecipientIban(), recipient);
    ASSERT_EQ(res, false);

    //SETRECIPIENT CON CONCILIATORY == FALSE;
    auto secondTesting = new Transaction ("sender", recipient, "causal" , 123.4 , "date", "time");
    bool secondRes = secondTesting->setRecipientIban(test);
    ASSERT_EQ(secondTesting->getRecipientIban(), test);
    ASSERT_EQ(secondRes, true);

    delete testing;
    delete secondTesting;

}

TEST (Transaction, TestSetDate) {
    string date = "date";
    string testDay = "day";
    string testMonth = "month";
    string testYear = "year";
    string test = testDay+"/"+testMonth+"/"+testYear;

    //SETDATE CON CONCILIATORY == TRUE
    auto testing = new Transaction ("sender", "recipient ", "causal", 123.4 , date , "time", true);
    bool res =testing->setDate(testDay, testMonth, testYear);
    ASSERT_EQ(testing->getDate(), date);
    ASSERT_EQ(res, false);

    //SETDATE CON CONCILIATORY == FALSE;
    auto secondTesting = new Transaction ("sender", "recpient", "causal" , 123.4 , date, "time");
    bool secondRes = secondTesting->setDate(testDay, testMonth, testYear);
    ASSERT_EQ(secondTesting->getDate(), test);
    ASSERT_EQ(secondRes, true);

    delete testing;
    delete secondTesting;

}


TEST (Transaction, TestSetTime) {
    string time = "time";
    string testHour = "hour";
    string testMinute = "minute";
    string test = testHour+":"+testMinute;

    //SETTIME CON CONCILIATORY == TRUE
    auto testing = new Transaction ("sender", "recipient ", "causal", 123.4 , "date" , time, true);
    bool res = testing->setTime(testHour, testMinute);
    ASSERT_EQ(testing->getTime(), time);
    ASSERT_EQ(res, false);

    //SETTIME CON CONCILIATORY == FALSE;
    auto secondTesting = new Transaction ("sender", "recpient", "causal" , 123.4 , "date", time);
    bool secondRes = secondTesting->setTime(testHour, testMinute);
    ASSERT_EQ(secondTesting->getTime(), test);
    ASSERT_EQ(secondRes, true);

    delete testing;
    delete secondTesting;

}