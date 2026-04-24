#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private :
	static void _PrintCurrency(clsCurrency& Currency)
	{
		cout << "Currency Card:\n\n";
		cout << "________________________\n";
		cout << "Currency     : " << Currency.GetCountry() << "\n";
		cout << "Currency Code: " << Currency.GetCountryCode() << "\n";
		cout << "Currency Name: " << Currency.GetCountryName() << "\n";
		cout << "Exchange Rate: " << Currency.GetRate() << "\n";
		cout << "______________________\n";
	}

public :

	static void ShowFindCurrencyScreen()
	{
		clsScreen::_DrawScreenHeader("Find Currency Screen");

		cout << "Find by: [1] Country Name, [2] Currency Code? ";
		short choice = clsInputValidate::ReadNumberBetween<short>(1, 2, "Invalid Number, Please Enter Number from 1 to 2");

		if(choice== 1)
		{
			cout << "Please enter Country Name: ";
			string Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindCurrencyByCountryName(Country);

			if (Currency.IsEmpty())
			{
				cout << "Currency with country name [" << Country << "] is not found :-(\n";
			}
			else
			{
				_PrintCurrency(Currency);
			}
		}

		else {
			cout << "Please enter Country Code: ";
			string Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindCurrencyByCountryCode(Country);

			if (Currency.IsEmpty())
			{
				cout << "Currency with country code [" << Country << "] is not found :-(\n";
			}
			else
			{
				_PrintCurrency(Currency);
			}
		}
	}
};

