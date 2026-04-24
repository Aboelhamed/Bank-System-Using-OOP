#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientsScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUserScreen.h"
#include "Global.h"
#include "clsLoginScreen.h"
#include "clsUsersRegisterList.h"
#include "clsCurrencyScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenuOptions { eClientList = 1, eAddNewClient, eDeleteClient, eUpdateClient, eFindClient, eTransactions, eManageUsers, eLoginRegister, eCurrencyExchange, eLogout };
    
    static void _GoBackToMainMenuScreen()
    {
        cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenu();
    }

    static int _ReadMainMenuOption()
    {
        cout << "\t\t\t\t\tEnter Number between 1 to 10: ";
        return clsInputValidate::ReadNumberBetween<int>(1, 10, "Invalid Number, Please Enter Number from 1 to 10");
    }

    static void _ShowAllClientsScreen()
    {
        clsClientsListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientsScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteClientsScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientsScreen()
    {
        clsUpdateClientScreen::ShowFindClientScreen();
    }

    static void _ShowFindClientsScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsScreen()
    {
        clsTransactionsScreen::ShowTransactionsScreen();
    }

    static void _ShowManageUsersScreen()
    {
        clsManageUserScreen::ShowManageUserMenuScreen();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsUsersRegisterList::ShowUsersList();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyScreen::ShowCurrencyExchangeMenu();
    }

    static void _ShowLogoutScreen()
    {
        CurrentUser = clsBankUser::Find("");
        
    }

    static void _PerformMainMenuScreen(enMainMenuOptions Option)
    {
        switch (Option)
        {
        case enMainMenuOptions::eClientList:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenuScreen();
            break;

        case enMainMenuOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenuScreen();
            break;
        
        case enMainMenuOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientsScreen();
            _GoBackToMainMenuScreen();
            break;
        
        case enMainMenuOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientsScreen();
            _GoBackToMainMenuScreen();
            break;
        
        case enMainMenuOptions::eFindClient:
            system("cls");
            _ShowFindClientsScreen();
            _GoBackToMainMenuScreen();
            break;
        
        case enMainMenuOptions::eTransactions:
            system("cls");
            _ShowTransactionsScreen();
            _GoBackToMainMenuScreen();
            break;
        
        case enMainMenuOptions::eManageUsers:
            system("cls");
            _ShowManageUsersScreen();
            _GoBackToMainMenuScreen();
            break;
        
        case enMainMenuOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenuScreen();
            break;
        
        case enMainMenuOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
			_GoBackToMainMenuScreen();

        case enMainMenuOptions::eLogout:
            system("cls");
            _ShowLogoutScreen();
            break;

        default:
            break;
        }
    }

public:

	static void ShowMainMenu()
	{
        system("cls");
        clsScreen::_DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1]  Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2]  Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3]  Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4]  Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5]  Find Client.\n";
        cout << setw(37) << left << "" << "\t[6]  Transactions.\n";
        cout << setw(37) << left << "" << "\t[7]  Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8]  Login Register.\n";
        cout << setw(37) << left << "" << "\t[9]  Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuScreen((enMainMenuOptions)_ReadMainMenuOption());
	}
};

