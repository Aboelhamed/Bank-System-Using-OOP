#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsWithdrawScreen :  protected clsScreen
{
private:

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

	static void ShowWithdrawScreen()
	{
		clsScreen::_DrawScreenHeader("\t    Withdraw Screen");

		string AccountNumber;
		char Answer;
		double WithdrawAmount;
		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is exist, choose anther one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient client = clsBankClient::Find(AccountNumber);
		_ClientCard(client);

		cout << "Please Enter Withdraw amount: ";
		WithdrawAmount = clsInputValidate::ReadNumber<double>();

		cout << "\nDo you sure you want to perform this transaction? (y)yes (n)no? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			if (client.Withdraw(WithdrawAmount))
			{
				cout << "\nAmount Withdraw Successfully :-)\n";
				cout << "\nNew Balance is:" << client.Balance << endl;
			}
			else
			{
				cout << "\nError!\nWithdraw Amount exceed your Balance :-(\n\n";
			}
		}
		else
		{
			cout << "\nAmount wasn\'t Withdraw\n\n";
		}
	}

};

