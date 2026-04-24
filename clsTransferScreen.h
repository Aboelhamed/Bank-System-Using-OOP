#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
private :

	static void _PrintClintCard(clsBankClient& client)
	{
		cout << "Client Card:\n";
		cout << "______________________________\n";
		cout << "Full Name     :" << client.getFullName()<<endl;
		cout << "Account Number:" << client.AccountNumber<<endl;
		cout << "Balance       :" << client.Balance<<endl;
		cout << "______________________________\n";
	}

	static string _ReadAccountNumber()
	{
		cout << "\nPlease Enter Account Number to Transfer From: ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, please enter another account number: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

public :

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t   Transfer Screen");
		
		clsBankClient client1 = clsBankClient::Find(_ReadAccountNumber());
		_PrintClintCard(client1);

		clsBankClient client2 = clsBankClient::Find(_ReadAccountNumber());
		_PrintClintCard(client2);
		
		cout << "\nEnter Transfer Amount: ";
		double Amount = clsInputValidate::ReadNumber<double>();
		
		char Answer;
		cout << "Are you sure you want to perform this operation? y/n? :";
		cin >> Answer;
		
		if (toupper(Answer) == 'Y')
		{
			if (client1.Transfer(client2, Amount, CurrentUser.Username))
			{
				cout << "\n\nTransfer Done Successfully :-)\n\n";
				_PrintClintCard(client1);
				cout << endl;
				_PrintClintCard(client2);
			}
			else
			{
				cout << "\nError!\nWithdraw Amount exceed your Balance :-(\n\n";
			}
		}
		else
		{
			cout << "\nAmount wasn\'t Transferd\n\n";
		}
	}

};