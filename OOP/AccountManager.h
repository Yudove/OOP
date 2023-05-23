#ifndef _ACCOUNTHANDLER_H_
#define _ACCOUNTHANDLER_H_

#include "Account.h"
#include "Container.h"

class AccountManager {
private:
    Container<Account*> accArr;
    int accNum;
public:
    AccountManager();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo() const;
    ~AccountManager();
protected:
    void MakeNormalAccount(void);
    void MakeCreditAccount(void);
};

#endif