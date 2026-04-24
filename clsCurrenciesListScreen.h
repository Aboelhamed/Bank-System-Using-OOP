#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"

using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{

private :

    static void _PrintCurrencyRecordLine(clsCurrency& Currency)
    {

        cout << "| " << setw(28) << left << Currency.GetCountry();
        cout << "| " << setw(7) << left << Currency.GetCountryCode();
        cout << "| " << setw(40) << left << Currency.GetCountryName();
        cout << "| " << setw(10) << left << Currency.GetRate();
    }


public:
    static void ShowCurrenciesList()
    {
        vector<clsCurrency>vCurrency = clsCurrency::GetCurrenciesList();

        string Title = "\t Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currencies";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(28) << "Country";
        cout << "| " << left << setw(7) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(10) << "Rate";
        cout << "\n" << setw(8) << left << "" << "_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrency.size() == 0)
        {
            cout << "\t\t\t\tNo Currencies Available In the System!\n\n";
        }
        else
        {
            for (clsCurrency& Currency : vCurrency)
            {
                cout << setw(8) << left << "";
                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }
            cout << setw(8) << left << "" << "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
        }
    }
};

