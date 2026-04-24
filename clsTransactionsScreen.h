#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogListScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private :
    enum enTransactionsOption{ eDeposit=1, eWithdraw, eTotalBalances, eTransfer, eTransferLog, eMainMenu};

    static short _ReadTransactionOption()
    {
        cout << "\t\t\t\t\tEnter Number between 1 to 6: ";
        return clsInputValidate::ReadNumberBetween<short>(1, 6, "Invalid Number, Enter Number Between 1 and 6: ");
    }

    static void _GoBackToTransactionsMenu()
    {
        cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Transactions Menu...\n";
        system("pause>0");
        ShowTransactionsScreen();
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogListScreen::ShowTransferLogList();
    }

    static void _PerformTransactionsOption(enTransactionsOption option)
    {
        switch (option)
        {
        case enTransactionsOption::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;

            case enTransactionsOption::eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsOption::eTotalBalances:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsOption::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsOption::eTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsOption::eMainMenu:
            break;

        default:
            break;
        }
    }


public :

	static void ShowTransactionsScreen()
	{

        if (!CheckPermissionsRight(clsBankUser::enPermissions::Transactions))
        {
            return;
        }

        system("cls");
        clsScreen::_DrawScreenHeader("\t\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsOption((enTransactionsOption)_ReadTransactionOption());
	}

};

