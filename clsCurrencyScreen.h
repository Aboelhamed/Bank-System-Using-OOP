#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankUser.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyScreen : protected clsScreen
{
private:
    enum enCurrencyExchangeMenuOptions { eCurrencyList = 1, eFindCurrency, eUpdateRate, eCurrencyCalculator, eMainMenu };

    static void _GoBackToCurrencyExchangeScreen()
    {
        cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Main Menu...\n";
        system("pause>0");
        ShowCurrencyExchangeMenu();
    }

    static int _ReadMainMenuOption()
    {
        cout << "\t\t\t\t\tEnter Number between 1 to 5: ";
        return clsInputValidate::ReadNumberBetween<short>(1, 5, "Invalid Number, Please Enter Number from 1 to 5");
    }

    static void _ShowAllCurrenciesScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreenScreen()
    {
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::showCurrencyCalculatorScreen();
    }

    static void _PerformMainMenuScreen(enCurrencyExchangeMenuOptions Option)
    {
        switch (Option)
        {
        case enCurrencyExchangeMenuOptions::eCurrencyList:
            system("cls");
            _ShowAllCurrenciesScreen();
            _GoBackToCurrencyExchangeScreen();
            break;

        case enCurrencyExchangeMenuOptions::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeScreen();
            break;

        case enCurrencyExchangeMenuOptions::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreenScreen();
            _GoBackToCurrencyExchangeScreen();
            break;

            case enCurrencyExchangeMenuOptions::eCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeScreen();
            break;

        case enCurrencyExchangeMenuOptions::eMainMenu:
            break;

        default:
            break;
        }
    }

public:

    static void ShowCurrencyExchangeMenu()
    {
        system("cls");

        if (!CheckPermissionsRight(clsBankUser::enPermissions::CurrencyExchange))
        {
            return;
        }

        clsScreen::_DrawScreenHeader("\t\Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1]  List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2]  Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3]  Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4]  Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5]  Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuScreen((enCurrencyExchangeMenuOptions)_ReadMainMenuOption());
    }

};

