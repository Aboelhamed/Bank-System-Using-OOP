#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
    static short _ReadPermissions()
    {

        short Permissions = 0;
        char Answer;


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions = clsBankUser::enPermissions::All;

            return Permissions;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions = Permissions | clsBankUser::enPermissions::ShowClientsList;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions = Permissions | clsBankUser::enPermissions::AddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions = Permissions | clsBankUser::enPermissions::DeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions = Permissions | clsBankUser::enPermissions::UpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions = Permissions | clsBankUser::enPermissions::FindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions = Permissions | clsBankUser::enPermissions::Transactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions = Permissions | clsBankUser::enPermissions::ManageUser;
        }

        cout << "\nLogin Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions = Permissions | clsBankUser::enPermissions::UserRegisterList;
        }

        cout << "\nCurrency Exchange? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions = Permissions | clsBankUser::enPermissions::CurrencyExchange;
        }


        return Permissions;
    }

    static void _ReadUserInfo(clsBankUser& user)
    {
        cout << "\nEnter First Name: ";
        user.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        user.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        user.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        user.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        user.Password = clsInputValidate::ReadString();

        user.Permissions = _ReadPermissions();
    }

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
        clsScreen::_DrawScreenHeader("\t   Update User Screen");

        string Username;
        char answer;

        cout << "\nPlease Enter user Username: ";
        Username = clsInputValidate::ReadString();

        while (!clsBankUser::IsUserExist(Username))
        {
            cout << "\nUsername is not found, choose anther one: ";
            Username = clsInputValidate::ReadString();
        }

        clsBankUser user = clsBankUser::Find(Username);
        _UserCard(user);

        cout << "\nDo you sure you want to Update this user? (y)yes (n)no? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            cout << "\nUpdate user Info:\n";
            cout << "________________________________________\n";

            _ReadUserInfo(user);
            clsBankUser::enSaveResult SaveResult = user.Save();
            switch (SaveResult)
            {
            case clsBankUser::enSaveResult::SaveFalidEmptyObject:
            {
                cout << "\n\nError account wasn\'t Save because it\'s Empty\n";
                break;
            }
            case clsBankUser::enSaveResult::SaveSuccessfully:
            {
                cout << "\n\nAccount Updated Successfully :-)\n\n";
                _UserCard(user);
                break;
            }

            default:
                break;
            }
        }
    }

};

