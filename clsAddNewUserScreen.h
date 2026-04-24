#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

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

public:

    static void ShowAddNewUserScreen()
    {
        clsScreen::_DrawScreenHeader("\t   Add User Screen");
        string Username;
        cout << "\nPlease Enter User Username: ";
        Username = clsInputValidate::ReadString();
        while (clsBankUser::IsUserExist(Username))
        {
            cout << "\nUsername is exist, choose anther one: ";
            Username = clsInputValidate::ReadString();
        }
        clsBankUser user = clsBankUser::GetAddNewUserObject(Username);
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
            cout << "\n\nAccount Added Successfully :-)\n\n";
            _UserCard(user);
            break;
        }
        case clsBankUser::enSaveResult::SaveFaildUserExist:
        {
            cout << "\n\nError Account Number is exist \n";
            break;
        }
        default:
            break;
        }
    }

};

