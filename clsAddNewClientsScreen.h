#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewClientsScreen : protected clsScreen
{
private :
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter First Name: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.Balance = clsInputValidate::ReadNumber<double>();
    }

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

public:
    
    static void ShowAddNewUserScreen()
    {
        if (!CheckPermissionsRight(clsBankUser::enPermissions::AddNewClient))
        {
            return;
        }
        clsScreen::_DrawScreenHeader("\t   Add Client Screen");
        string AccountNumber;
        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is exist, choose anther one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(client);

        clsBankClient::enSaveResults SaveResult =  client.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::SaveFaild:
        {
            cout << "\n\nError account wasn\'t Save because it\'s Empty\n";
            break;
        }
        case clsBankClient::enSaveResults::SaveSucceeded:
        {
            cout << "\n\nAccount Added Successfully :-)\n\n";
            _ClientCard(client);
            break;
        }
        case clsBankClient::enSaveResults::SaveFailedAccountNumberExist:
        {
            cout << "\n\nError Account Number is exist \n";
            break;
        }
        default:
            break;
        }
    }

};

