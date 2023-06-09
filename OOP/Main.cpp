#include "BankingCommonDecl.h"
#include "AccountManager.h"

int main() {
    AccountManager manager;
    int choice;
    while (true) {
        manager.ShowMenu();
        cout << "����: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrawMoney();
            break;
        case INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}