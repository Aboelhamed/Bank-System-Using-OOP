#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"

using namespace std;

class clsUpdateRateScreen : protected clsScreen
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

	static void ShowUpdateRateScreen()
	{
		clsScreen::_DrawScreenHeader("Update Currency Rate Screen");

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

			char answer;
			cout << "Are you sure you want to update this currency? y/n? ";
			cin >> answer;
			if (toupper(answer) == 'Y')
			{
				cout << "Update Current Rate:\n";
				cout << "__________________\n";
				cout << "Enter New Rate: ";
				double NewRate = clsInputValidate::ReadNumber<double>();
				Currency.Update(NewRate);
				cout << "Currency Rate Updated Successfully :-)\n";

				_PrintCurrency(Currency);
			}
			else
			{
				cout << "Currency Rate Not Update :-(\n";
			}
		}
	}
};

