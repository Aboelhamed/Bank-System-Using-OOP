#pragma once
#include <iostream>
#include "clsBankUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{

private :

	static bool _Login()
	{
		bool _LoginFail = false;
		short _TrailCount = 0;
		do {
			if (_LoginFail)
			{
				_TrailCount++;
				cout << "\nInvalid Username or Password!\n";
				cout << "You have " << 3 - _TrailCount << " Trails to login.\n\n";
			}

			if (_TrailCount==3)
			{
				cout << "You are locked after 3 trials\n";
				return false;
			}

			cout << "Enter Username: ";
			string Username = clsInputValidate::ReadString();

			cout << "Enter Password: ";
			string Password = clsInputValidate::ReadString();

			CurrentUser = clsBankUser::Find(Username, Password);

			_LoginFail = CurrentUser.IsEmpty();

		} while (_LoginFail && _TrailCount != 3);

		CurrentUser.LoadLineToUserLoginRegisterFile();
		clsMainScreen::ShowMainMenu();
		return true;
	}

public :

	static bool ShowLoginScreen()
	{

		clsScreen::_DrawScreenHeader("\t\tLogin Screen");
		return _Login();

	}

};