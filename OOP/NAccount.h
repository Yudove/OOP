#ifndef _NORMALACCOUNT_H_
#define _NORMALACCOUNT_H_

#include "Account.h"
#include "String.h"
#include "AccountException.h"

class NormalAccount : public Account {
private:
    int interRate;
public:
    NormalAccount(int ID, int money, String name, int rate)
        :Account(ID, money, name), interRate(rate) {}

    virtual void Deposit(int money) {
        if (money < 0)
            throw MinusException(money);
        Account::Deposit(money);
        Account::Deposit(money * (interRate / 100.0));
    }
};

#endif