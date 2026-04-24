#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:

    static void _UserCard(clsBankUser& user)
    {
        cout << "\t\tUser Card:\n";
        cout << "________________________________________\n";
        cout << "First Name    :" << user.FirstName << endl;
        cout << "Last Name     :" << user.LastName << endl;
        cout << "Full Name     :" << user.getFullName() << endl;
        cout << "Email         :" << user.Email << endl;
        cout << "Phone         :" << user.Phone << endl;
        cout << "Username      :" << user.Username << endl;
        cout << "Password      :" << user.Password << endl;
        cout << "Permissions   :" << user.Permissions << endl;
        cout << "________________________________________\n";
    }


public:

    static void ShowUpdateUserScreen()
    {
        clsScreen::_DrawScreenHeader("\t   Find User Screen");

        string Username;

        cout << "\nPlease Enter User Account Number: ";
        Username = clsInputValidate::ReadString();

        while (!clsBankUser::IsUserExist(Username))
        {
            cout << "\nAccount Number is not found, choose anther one: ";
            Username = clsInputValidate::ReadString();
        }

        clsBankUser User = clsBankUser::Find(Username);

        if (User.IsEmpty())
        {
            cout << "User was\'t found";
        }
        else
        {
            _UserCard(User);
        }
    }

};