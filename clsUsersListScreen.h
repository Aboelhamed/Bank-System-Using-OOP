#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankUser.h"
#include <vector> 

using namespace std;

class clsUsersListScreen : protected clsScreen
{

    static void PrintClientRecordLine(clsBankUser& User)
    {

        cout << "| " << setw(11) << left << User.Username;
        cout << "| " << setw(20) << left << User.getFullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;
    }


public:
    static void ShowClientsList()
    {
        vector<clsBankUser>vUsers = clsBankUser::GetUserList();

        string Title = "\t Clients List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") Clients";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(11) << "Username";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "\n" << setw(8) << left << "" << "_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
        {
            cout << "\t\t\t\tNo Clients Available In the System!\n\n";
        }
        else
        {
            for (clsBankUser& user : vUsers)
            {
                cout << setw(8) << left << "";
                PrintClientRecordLine(user);
                cout << endl;
            }
            cout << setw(8) << left << "" << "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
        }
    }

};

