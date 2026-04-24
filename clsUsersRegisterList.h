#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankUser.h"

using namespace std;

class clsUsersRegisterList :  protected clsScreen
{

private:

    static void PrintUserRegisterRecordLine(clsBankUser::stLoginRegisterData& stUser)
    {

        cout << "| " << setw(35) << left << stUser.Date;
        cout << "| " << setw(22) << left << stUser.Username;
        cout << "| " << setw(22) << left << stUser.Password;
        cout << "| " << setw(10) << left << stUser.Permissions;
    }


public:
    static void ShowUsersList()
    {
        if (!CheckPermissionsRight(clsBankUser::enPermissions::UserRegisterList))
        {
            return;
        }
        vector<clsBankUser::stLoginRegisterData>vUsers = clsBankUser::GetUserRegisterList();

        string Title = "\t Users Register List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") Users";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date";
        cout << "| " << left << setw(22) << "Username";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << "\n" << setw(8) << left << "" << "_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
        {
            cout << "\t\t\t\tNo Users Available In the System!";
        }
        else
        {
            for (clsBankUser::stLoginRegisterData& User : vUsers)
            {
                cout << setw(8) << left << "";
                PrintUserRegisterRecordLine(User);
                cout << endl;
            }
            cout << setw(8) << left << "" << "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
        }
    }



};

