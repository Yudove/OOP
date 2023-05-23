#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "String.h"

class Account {
private:
    int accID;
    int balance;
    String cusName;
public:
    Account(int ID, int money, String name);
    int GetAccID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
};

#endif