#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include "clsString.h"
using namespace std;

class clsDate
{
private:
	short _Second;
	short _Minute;
	short _Hour;
	short _Day;
	short _Month;
	short _Year;
public:
	clsDate()
	{
		time_t t = time(0);
		tm* dt = localtime(&t);
		_Year = dt->tm_year + 1900;
		_Month = dt->tm_mon + 1;
		_Day = dt->tm_mday;
		
	}

	clsDate(string S1)
	{
		vector<string>vDate;
		vDate = clsString::SplitString(S1, "/");
		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	static bool IsLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	static short DaysInMonth(short month, short year)
	{
		if (month==2)
		{
			return IsLeapYear(year) ? 29 : 28;
		}
		short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return arr[month - 1];
	}

	static bool IsValidDate(clsDate Date)
	{
		if (Date._Month>12||Date._Month<1)
		{
			return false;
		}
		if (Date._Day != DaysInMonth(Date._Month, Date._Year))
		{
			return false;
		}
		
		return true;
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return Date1._Year == Date2._Year ? Date1._Month == Date2._Month ? Date1._Day == Date2._Day : false : false;
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{

		return !IsDate1EqualDate2(Date1,Date2)? Date1._Year < Date2._Year ? true : Date1._Year == Date2._Year ? Date1._Month < Date2._Month ? true : Date1._Month == Date2._Month? Date1._Day < Date2._Day : false :  false : false;
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return !(IsDate1BeforeDate2(Date1, Date2) || IsDate1EqualDate2(Date1, Date2));
	}

	string DateToString()
	{
		return to_string(_Day)+"/" + to_string(_Month) + "/" + to_string(_Year);
	}
	
	static string DateToString(clsDate date)
	{
		return to_string(date._Day) + "/" + to_string(date._Month) + "/" + to_string(date._Year);
	}

	static string DateDetailsToString(clsDate date)
	{
		time_t t = time(0);
		tm* dt = localtime(&t);

		date._Hour = dt->tm_hour;
		date._Minute = dt->tm_min;
		date._Second = dt->tm_sec;

		return DateToString(date) + " - " + to_string(date._Hour) + ":" + to_string(date._Minute) + ":" + to_string(date._Second);
	}

	static string DateToString(short Day, short Month, short Year)
	{
		return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year);
	}

	void print()
	{
		cout << _Day << "/" << _Month << "/" << _Year << endl;
	}
};

