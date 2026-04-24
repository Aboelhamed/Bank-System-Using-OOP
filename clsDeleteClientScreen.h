#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{

    static void _ClientCard(clsBankClient& client)
    {
        cout << "Client Card:\n";
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

	static void ShowDeleteClientScreen()
	{
        if (!CheckPermissionsRight(clsBankUser::enPermissions::DeleteClient))
        {
            return;
        }


        clsScreen::_DrawScreenHeader("\t  Delete Client Screen");
        string AccountNumber;
        char answer;
        
        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found, choose anther one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);
        _ClientCard(client);

        cout << "\nDo you sure you want to delete this client? (y)yes (n)no? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            if (client.Delete())
            {
                cout << "\n\nClient Deleted Successfully :-)\n";
                _ClientCard(client);
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

