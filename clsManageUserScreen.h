#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUserScreen : protected clsScreen
{
private :
    enum enManageMenuOption { eListUser = 1, eAddNewUser, eDeleteUser, eUpdateUser, eFindUser, eMainMenu };

    static void _GoBackToMainMenuScreen()
    {
        cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowManageUserMenuScreen();
    }

    static int _ReadManageUserOption()
    {
        cout << "\t\t\t\t\tEnter Number between 1 to 6: ";
        return clsInputValidate::ReadNumberBetween<short>(1, 6, "Invalid Number, Please Enter Number from 1 to 8");
    }

    static void _ShowAllUsersScreen()
    {
        clsUsersListScreen::ShowClientsList();
    }

    static void _AddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _DeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _UpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _FindUserScreen()
    {
        clsFindUserScreen::ShowUpdateUserScreen();
    }

    static void _PerformManageUserScreen(enManageMenuOption option)
    {
        switch (option)
        {
        case enManageMenuOption::eListUser:
            system("cls");
            _ShowAllUsersScreen();
            _GoBackToMainMenuScreen();
            break;

        case enManageMenuOption::eAddNewUser:
            system("cls");
            _AddNewUserScreen();
            _GoBackToMainMenuScreen();
            break;

        case enManageMenuOption::eDeleteUser:
            system("cls");
            _DeleteUserScreen();
            _GoBackToMainMenuScreen();
            break;

        case enManageMenuOption::eUpdateUser:
            system("cls");
            _UpdateUserScreen();
            _GoBackToMainMenuScreen();
            break;

        case enManageMenuOption::eFindUser:
            system("cls");
            _FindUserScreen();
            _GoBackToMainMenuScreen();
            break;

        case enManageMenuOption::eMainMenu:
            break;
        }
    }


public :

	static void ShowManageUserMenuScreen()
	{

        if (!CheckPermissionsRight(clsBankUser::enPermissions::ManageUser))
        {
            return;
        }

        system("cls");
        clsScreen::_DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t   Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List User.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUserScreen((enManageMenuOption)_ReadManageUserOption());
	}

};

