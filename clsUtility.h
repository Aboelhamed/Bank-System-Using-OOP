#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;

class clsUtility
{
public:

	static enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4, MixedChar = 5 };
	
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int RandNum = rand() % (To - From + 1) + From;
		return RandNum;
	}
	
	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SmallLetter:
		{
			return char(RandomNumber(97, 122)); // char( 110 ) = n
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		case enCharType::MixedChar:
		{
			return GetRandomCharacter((enCharType)RandomNumber(1, 4));
			break;
		}
		}
	}
	
	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++) // 1 <= 4 ? | 2 <= 4 ...
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}
	
	static string GenerateKey(enCharType charType)
	{
		string Key = "";
		Key = GenerateWord(charType, 4) + "-";
		Key = Key + GenerateWord(charType, 4) + "-";
		Key = Key + GenerateWord(charType, 4) + "-";
		Key = Key + GenerateWord(charType, 4);
		return Key;
	}
	
	static void GenerateKeys(short NumberOfKeys, enCharType charType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Kay [" << i << "] : " << GenerateKey(charType) << endl;
		}
	}
	
	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, short from, short to)
		// & main لترجع ) تخزن ( القيمة المدخلة في
	{
		for (int i = 0; i < arrLength; i++)
			// index[0] == arr مكان تخزين أول قيمة في
			arr[i] = RandomNumber(from, to); // [1] == arr أول قيمة عنصر في
	}
	
	static void FillArrayWithRandomWords(string arr[100], int arrLength, clsUtility::enCharType charType, short wordLength) // & main لترجع ) تخزن ( القيمة المدخلة في
	{
		for (int i = 0; i < arrLength; i++) // index[0] == arr مكان تخزين
			arr[i] = GenerateWord(charType , wordLength); // [1] == arr أول قيمة عنصر
	}
	
	static void FillArrayWithRandomKeys(string arr[100], int arrLength, clsUtility::enCharType charType) // & main لترجع ) تخزن ( القيمة المدخلة في
	{
		for (int i = 0; i < arrLength; i++) // index[0] == arr مكان تخزين
			arr[i] = GenerateKey(charType); // [1] == arr أول قيمة عنصر
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}
	
	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static string EncryptText(string Text, short EncryptionKey=2)
	{
		// Text = Saeed
		// EncryptionKey = 2
		for (int i = 0; i <= Text.length(); i++)
		{ // Text.length() ( تجزئة النص حرف حرف : موقع الحرف ) إنديكس
			Text[i] = char((int)Text[i] + EncryptionKey);
			// Text[i] == (int) Text[S] == Text[83] + 2 == (char) Text[85] << U[0]; .....
		}
		return Text; // Ucggf
	}
	
	static string DecryptText(string Text, short EncryptionKey=2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
			// Text[i] == (int) Text[U] == Text[85] - 2 == (char) Text[83] << S[0]; .....
		}
		return Text; // Saeed
	}

	static void Swap(int& number1, int& number2)
	{
		int temp = 0;
		temp = number1;
		number1 = number2;
		number2 = temp;
	}

	static void Swap(double& number1, double& number2)
	{
		double temp = 0;
		temp = number1;
		number1 = number2;
		number2 = temp;
	}

	static void Swap(string& S1, string& S2)
	{
		string temp;
		temp = S1;
		S1 = S2;
		S2 = temp;
	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate temp;
		temp = Date1;
		Date1 = Date2;
		Date2 = temp;
	}

};
