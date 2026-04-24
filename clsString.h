#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{
private:
	string _Value;
public:
	clsString()
	{

	}
	clsString(string Value)
	{
		_Value = Value;
	}
	void setValue(string Value)
	{
		_Value = Value;
	}
	string getValue()
	{
		return _Value;
	}
	__declspec(property(get = getValue, put = setValue))string Value;

	static short NumberOfWordsInString(string str)
	{
		short pos = 0;
		string dim = " ";
		int counter = 0;
		string word;
		while ((pos = str.find(dim)) != string::npos)
		{
			word = str.substr(0, pos);
			if (!word.empty())
			{
				counter++;
			}
			str.erase(0, pos + dim.length());
		}
		if (!str.empty())
			counter++;
		return counter;
	}
	short NumberOfWordsInString()
	{
		return NumberOfWordsInString(_Value);
	}

	static void PrintFirstLetterOfEachWord(string S1)
	{
		bool IsFirstOfWord = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsFirstOfWord&&S1[i]!=' ')
			{
				cout << S1[i] << endl;
			}
			IsFirstOfWord = S1[i] == ' ' ? true : false;
		}
	}
	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static string ConvertFirstLetterOfWordIntoUpperCase(string S1)
	{
		bool IsFirstOfWord = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsFirstOfWord && S1[i] != ' ')
			{
				S1[i]=toupper(S1[i]);
			}
			IsFirstOfWord = S1[i] == ' ' ? true : false;
		}
		return S1;
	}
	string ConvertFirstLetterOfWordIntoUpperCase()
	{
		return ConvertFirstLetterOfWordIntoUpperCase(_Value);
	}

	static string ConvertFirstLetterOfWordIntoLowerCase(string S1)
	{
		bool IsFirstOfWord = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsFirstOfWord && S1[i] != ' ')
			{
				S1[i] = tolower(S1[i]);
			}
			IsFirstOfWord = S1[i] == ' ' ? true : false;
		}
		return S1;
	}
	string ConvertFirstLetterOfWordIntoLowerCase()
	{
		return ConvertFirstLetterOfWordIntoLowerCase(_Value);
	}

	static void CountOfUpperCaseAndLowerCaseCharacter(string S1)
	{
		short CountOfUpperCaseCharacter = 0;
		short CountOfLowerCaseCharacter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i]!=' ')
			{
				S1[i] = isupper(S1[i]) ? CountOfUpperCaseCharacter++ : CountOfLowerCaseCharacter++;
			}
		}
		cout << "Count Of UpperCase Charachter is: " << CountOfUpperCaseCharacter << endl;
		cout << "Count Of LowerCase Charachter is: " << CountOfLowerCaseCharacter << endl;
	}
	void CountOfUpperCaseAndLowerCaseCharacter()
	{
		return CountOfUpperCaseAndLowerCaseCharacter(_Value);
	}

	static vector<string> SplitString(string S1,string delim)
	{
		short pos = 0;
		string word = "";
		vector<string>vString;
		while ((pos = S1.find(delim)) != string::npos)
		{
			word = S1.substr(0, pos);
			vString.push_back(word);
			S1.erase(0, pos + delim.length());
		}
		if (!S1.empty())
			vString.push_back(S1);
		return vString;
	}
	vector<string> SplitString(string delim)
	{
		return SplitString(_Value, delim);
	}

	static string UpperAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	string UpperAllString()
	{
		return UpperAllString(_Value);
	}
};