#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
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

	static clsCurrency _ReadCurrency()
	{
		string CountryCode = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindCurrencyByCountryCode(CountryCode);

		while (!Currency.IsCurrencyExist())
		{
			cout << "Currency with country code [" << CountryCode << "] is not found, please enter another country code\n";
			CountryCode = clsInputValidate::ReadString();
			Currency = clsCurrency::FindCurrencyByCountryCode(CountryCode);
		}
		return Currency;
	}

public :
	
	static void showCurrencyCalculatorScreen()
	{
		char answer;
		do {
			clsScreen::_DrawScreenHeader("Currency Calculator Screen");

			cout << "Please enter currency1: ";
			clsCurrency Currency1 = _ReadCurrency();
			cout << "Please enter currency2: ";
			clsCurrency Currency2 = _ReadCurrency();

			cout << "Enter amount to exchange: ";
			double Amount = clsInputValidate::ReadNumber<double>();

			cout << "\nConverting From:\n";
			_PrintCurrency(Currency1);

			cout << "\nConverting to:\n";
			_PrintCurrency(Currency2);

			cout << Amount << " " << Currency1.GetCountryCode() << " = " << Currency1.CalculateCurrencyRate(Amount, Currency2) << " " << Currency2.GetCountryCode() << "\n\n";

			cout << "Are you sure you want to perform another calculation? y/n? ";
			cin >> answer;
		} while (toupper(answer) == 'Y');
			
	}
};
