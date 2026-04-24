#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"

using namespace std;

class clsCurrency
{
private :
	enum enMode { EmptyMode, UpdateMode };
	enMode _Mode;
	string _Country;
	string _CountryCode;
	string _CountryName;
	float _Rate;

	static clsCurrency _ConvertLineToObject(string Line)
	{
		vector<string> vCurrencyData = clsString::SplitString(Line, "#//#");

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}

	string _ConvertObjectToLine(clsCurrency Currency)
	{
		string S1 = "";
		S1 += Currency.GetCountry() + "#//#";
		S1 += Currency.GetCountryCode() + "#//#";
		S1 += Currency.GetCountryName() + "#//#";
		S1 += to_string(Currency.GetRate());
		return S1;
	}

	static vector <clsCurrency> _LoadCurrenciesFromFile()
	{
		vector <clsCurrency> vCurrencies;
		fstream MyFile("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				vCurrencies.push_back(_ConvertLineToObject(Line));

			}
			MyFile.close();
		}
		return vCurrencies;
	}

	void _SaveFile(vector <clsCurrency> vCurrencies)
	{
		fstream MyFile("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsCurrency& Currency : vCurrencies)
			{
				MyFile << _ConvertObjectToLine(Currency) << endl;
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsCurrency> vCurrencies = _LoadCurrenciesFromFile();
		for (clsCurrency& Currency : vCurrencies)
		{
			if (Currency.GetCountry() == GetCountry())
			{
				Currency = *this;
				break;
			}
		}
		_SaveFile(vCurrencies);
	}
	
public :

	clsCurrency(enMode Mode, string Country, string CountryCode, string CountryName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CountryCode = CountryCode;
		_CountryName = CountryName;
		_Rate = Rate;
	}

	enMode getMode() { return _Mode; }
	string GetCountry() { return _Country; }
	string GetCountryCode() { return _CountryCode; }
	string GetCountryName() { return _CountryName; }
	float GetRate() { return _Rate; }

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsCurrency FindCurrency(string Country, bool WithCountry, string CountryCode, bool WithCountryCode)
	{
		vector <clsCurrency> vCurrencies = _LoadCurrenciesFromFile();
		Country = clsString::UpperAllString(Country);
		CountryCode = clsString::UpperAllString(CountryCode);
		for (clsCurrency& Currency : vCurrencies)
		{
			if ((clsString::UpperAllString(Currency.GetCountry()) == Country || !WithCountry) && (clsString::UpperAllString(Currency.GetCountryCode()) == CountryCode || !WithCountryCode))
			{
				return Currency;
			}
		}
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static clsCurrency FindCurrencyByCountryName(string Country)
	{
		return FindCurrency(Country, true, "", false);
	}
	
	static clsCurrency FindCurrencyByCountryCode(string CountryCode)
	{
		return FindCurrency("", false, CountryCode, true);
	}

	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesFromFile();
	}

	void Update(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	bool IsCurrencyExist()
	{
		clsCurrency C1 = FindCurrency(GetCountry(), true, GetCountryCode(), false);
		return !C1.IsEmpty();
	}

	double CalculateCurrencyRate(double Amount, clsCurrency ToCurrency)
	{
		return ((Amount / GetRate()) * ToCurrency.GetRate());
	}

};

