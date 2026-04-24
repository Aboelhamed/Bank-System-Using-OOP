#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:

    static void _UserCard(clsBankUser& user)
    {
        cout << "User Card:\n";
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

public :

    static void ShowDeleteUserScreen()
    {
        clsScreen::_DrawScreenHeader("\t  Delete User Screen");

        string Username;
        char Answer;

        cout << "\nPlease Enter User Username: ";
        Username = clsInputValidate::ReadString();
        while (!clsBankUser::IsUserExist(Username))
        {
            cout << "\nUsername is not found, choose anther one: ";
            Username = clsInputValidate::ReadString();
        }
        clsBankUser user = clsBankUser::Find(Username);

        _UserCard(user);

        cout << "\nDo you sure you want to delete this user? (y)yes (n)no? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            if (user.Delete())
            {
                cout << "\n\nClient Deleted Successfully :-)\n";
                _UserCard(user);
            }
            else
            {
                cout << "\nError!\nClient Wasn\'t deleted.";
            }
        }
        else
        {
            {
                cout << "\nClient wasn\'t deleted\n";
            }
        }
    }
};

