#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsUtility.h"

using namespace std;

class clsInputValidate
{
public:
	template<typename T>
	static bool IsNumberBetween(T number, T from, T to)
	{
		return (number <= to && number >= from);
	}
	
	static bool IsDateBetween(clsDate Date, clsDate from, clsDate to)
	{
		if (clsDate::IsDate1AfterDate2(from,to))
		{
			clsUtility::Swap(from, to);
		}

		return ((clsDate::IsDate1AfterDate2(Date, from) || clsDate::IsDate1EqualDate2(Date, from)) && (clsDate::IsDate1BeforeDate2(Date, to) || clsDate::IsDate1EqualDate2(Date, to)));
	}

	template<typename T>
	static T ReadNumber(string message = "Invalid Number, Enter again:\n")
	{
		T number;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message;
		}
		return number;
	}

	template<typename T>
	static T ReadNumberBetween(T from, T to, string Message)
	{
		T number = ReadNumber<T>();
		while (!IsNumberBetween(number, from, to))
		{
			cout << Message;
			number = ReadNumber<T>();
		}
		return number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S1 = "";

		getline(cin >> ws, S1);
		
		return S1;
	}

};

