#include "BankingCommondecl.h"
#include "AccountManager.h"
#include "Account.h"
#include "NAccount.h"
#include "HCAccount.h"
#include "String.h"

void AccountManager::ShowMenu()const {
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountManager::MakeAccount() {
    int sel;
    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌 ";
    cout << "2. 신용신뢰계좌 " << endl;
    cout << "선택: ";
    cin >> sel;

    if (sel == NORMAL)
        MakeNormalAccount();
    else
        MakeCreditAccount();
}

void AccountManager::MakeNormalAccount() {
    int id;
    String name;
    int balance;
    int interRate;

    cout << "[보통예금계좌 개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interRate;
    cout << endl;

    accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountManager::MakeCreditAccount() {
    int id;
    String name;
    int balance;
    int interRate;
    int creditLevel;

    cout << "[신용신뢰계좌 개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interRate;
    cout << "신용등급(1toA, 2toB, 3toC): "; cin >> creditLevel;
    cout << endl;

    switch (creditLevel) {
    case 1:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
        break;
    case 2:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
        break;
    case 3:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
    }
}

void AccountManager::DepositMoney() {
    int money;
    int id;
    cout << "[입 금]" << endl;
    cout << "계좌ID: "; cin >> id;

    while (true) {
        cout << "입금액: "; cin >> money;
        try {
            for (int i = 0; i < accNum; ++i) {
                if (accArr[i]->GetAccID() == id) {
                    accArr[i]->Deposit(money);
                    cout << "입금완료" << endl << endl;
                    return;
                }
            }
        }
        catch (MinusException& expt) {
            expt.ShowExceptionInfo();
            cout << "입금액만 재입력하세요." << endl;
        }
    }
}

void AccountManager::WithdrawMoney() {
    int money;
    int id;
    cout << "[출금]" << endl;
    cout << "계좌ID: "; cin >> id;

    while (true) {
        cout << "출금액: "; cin >> money;

        try {
            for (int i = 0; i < accNum; ++i) {
                if (accArr[i]->GetAccID() == id) {
                    accArr[i]->Withdraw(money);
                    cout << "출금완료" << endl << endl;
                    return;
                }
            }
            cout << "유효하지 않은 ID 입니다." << endl << endl;
            return;
        }
        catch (MinusException& expt) {
            expt.ShowExceptionInfo();
            cout << "입금액만 재입력하세요." << endl;
        }
        catch (InsuffException& expt) {
            expt.ShowExceptionInfo();
            cout << "출금액만 재입력하세요." << endl;
        }
    }
}

AccountManager::AccountManager() : accNum(0) {}

void AccountManager::ShowAllAccInfo() const {
    for (int i = 0; i < accNum; ++i) {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

AccountManager::~AccountManager() {
    for (int i = 0; i < accNum; ++i)
        delete accArr[i];
}