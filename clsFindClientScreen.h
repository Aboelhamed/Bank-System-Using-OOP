#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
{
private :

    static void _ClientCard(clsBankClient& client)
    {
        cout << "\n\nClient Card:\n";
        cout << "________________________________________\n";
        cout << "First Name    :" << client.FirstName << endl;
        cout << "Last Name     :" << client.LastName << endl;
        cout << "Full Name     :" << client.getFullName() << endl;
        cout << "Email         :" << client.Email << endl;
        cout << "Phone         :" << client.Phone << endl;
        cout << "Account Number:" << client.AccountNumber << endl;
        cout << "PinCode       :" << client.PinCode << endl;
        cout << "Balance       :" << client.Balance << endl;
        cout << "________________________________________\n";
    }

public :

    static void ShowFindClientScreen()
    {
        if (!CheckPermissionsRight(clsBankUser::enPermissions::FindClient))
        {
            return;
        }

        clsScreen::_DrawScreenHeader("\t   Find Client Screen");

        string AccountNumber;

        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found, choose anther one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);

        if (client.IsEmpty())
        {
            cout << "Client was\'t found";
        }
        else
        {
            _ClientCard(client);
        }
    }
};

