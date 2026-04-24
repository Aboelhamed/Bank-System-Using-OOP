#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>
#include <vector>

using namespace std;

class clsBankClient :public clsPerson
{
private:
	enum enMode { EmptyMode, UpdateMode, AddMode };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _Balance = 0;
	bool _IsMarkDelete = false;
	struct stTransferLog;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string>vClient = clsString::SplitString(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stod(vClient[6]));
	}

	static stTransferLog _ConvertLineToTransferLog(string Line, string Seperator = "#//#")
	{
		stTransferLog Transfers;
		vector<string>vTransfer = clsString::SplitString(Line, Seperator);
		Transfers.Date = vTransfer[0];
		Transfers.SourceAccNumber = vTransfer[1];
		Transfers.DisAccNumber = vTransfer[2];
		Transfers.Amount = stod(vTransfer[3]);
		Transfers.SourceBalance = stod(vTransfer[4]);
		Transfers.DisBalance = stod(vTransfer[5]);
		Transfers.Username = vTransfer[6];

		return Transfers;
	}

	static string _ConvertClientObjectToLine(clsBankClient client, string Seperator = "#//#")
	{
		string S1 = "";

		S1 = client.getFirstName() + Seperator;
		S1 += client.getLastName() + Seperator;
		S1 += client.getEmail() + Seperator;
		S1 += client.getPhone() + Seperator;
		S1 += client.getAccountNumber() + Seperator;
		S1 += client.getPinCode() + Seperator;
		S1 += to_string(client.getBalance());

		return S1;

	}

	string _ConvertTransferLogToLine(clsBankClient TransferTo, double Amount,string Username, string Seperator = "#//#")
	{
		string S1 = "";

		S1 = clsDate::DateDetailsToString(clsDate()) + Seperator;
		S1 += AccountNumber + Seperator;
		S1 += TransferTo.AccountNumber + Seperator;
		S1 += to_string(Amount) + Seperator;
		S1 += to_string(Balance) + Seperator;
		S1 += to_string(TransferTo.Balance) + Seperator;
		S1 += Username;

		return S1;

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadClientData()
	{
		vector<clsBankClient>vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);		//Read Only
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				vClients.push_back(_ConvertLineToClientObject(Line));
				
			}
			MyFile.close();
		}
		return vClients;
	}

	static vector<stTransferLog> _LoadTransferLogData()
	{
		vector<stTransferLog>vTransfers;
		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::in);		//Read Only

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{

				vTransfers.push_back(_ConvertLineToTransferLog(Line));

			}

			MyFile.close();
		}
		return vTransfers;
	}

	void _LoadLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);		//Read and Write
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
		}
		MyFile.close();
	}

	void _LoadTransferLogLineToFile(clsBankClient TransferTo, double Amount, string Username)
	{
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);		//Read and Write
		if (MyFile.is_open())
		{
			MyFile << _ConvertTransferLogToLine(TransferTo, Amount, Username) << endl;
		}
		MyFile.close();
	}

	void _SaveClientData(vector<clsBankClient>vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);		//Write Only
		if (MyFile.is_open())
		{
			for (clsBankClient& client : vClients)
			{
				if(!client._IsMarkDelete)
				{
					MyFile << _ConvertClientObjectToLine(client) << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsBankClient>vClients = _LoadClientData();
		for (clsBankClient& client : vClients)
		{
			if (client.AccountNumber==AccountNumber)
			{
				client = *this;
				break;
			}
		}
		_SaveClientData(vClients);
	}

	void _AddNewClient()
	{
		_LoadLineToFile(_ConvertClientObjectToLine(*this));
	}

public:

	struct stTransferLog
	{
		string Date;
		string SourceAccNumber;
		string DisAccNumber;
		double Amount;
		double SourceBalance;
		double DisBalance;
		string Username;
	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double Balance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;
	}
	
	void setAccountNumber(string AccountNumber)		//set property
	{
		_AccountNumber = AccountNumber;
	}
	
	string getAccountNumber()		//get property
	{
		return _AccountNumber;
	}

	__declspec(property(get = getAccountNumber, put = setAccountNumber))string AccountNumber;

	void setPinCode(string PinCode)		//set property
	{
		_PinCode = PinCode;
	}
	
	string getPinCode()		//get property
	{
		return _PinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode))string PinCode;

	void setBalance(double Balance)		//set property
	{
		_Balance = Balance;
	}
	
	double getBalance()		//get property
	{
		return _Balance;
	}
	
	__declspec(property(get = getBalance, put = setBalance))double Balance;

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsBankClient Find(string AccountNumber, string PinCode, bool WithPinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);		//Read Only
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber == AccountNumber && (!WithPinCode || Client.PinCode == PinCode))
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
			return _GetEmptyClientObject();
		}
	}

	static clsBankClient Find(string AccountNumber)
	{
		return Find(AccountNumber, "", false);
	}
	
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		return Find(AccountNumber, PinCode, true);
	}

	bool Delete()
	{
		vector<clsBankClient>vClients = _LoadClientData();

		for (clsBankClient& client : vClients)
		{
			if (client.AccountNumber == AccountNumber)
			{
				client._IsMarkDelete = true;
				break;
			}
		}
		_SaveClientData(vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient client = Find(AccountNumber);
		return client.IsEmpty() ? false : true;
	}

	enum enSaveResults { SaveFaild, SaveSucceeded, SaveFailedAccountNumberExist};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::SaveFaild;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::SaveSucceeded;
		}
		case enMode::AddMode:
		{
			if (IsClientExist(_AccountNumber))
			{
				return enSaveResults::SaveFailedAccountNumberExist;
			}
			else
			{
				_AddNewClient();
				return enSaveResults::SaveSucceeded;
			}
		}
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientData();
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClients = _LoadClientData();
		double TotalBalances = 0;
		for (clsBankClient& client : vClients)
		{
			TotalBalances += client.Balance;
		}
		return TotalBalances;
	}

	bool Deposit(double DepositAmount)
	{
		_Balance += DepositAmount;
		Save();
		return true;
	}

	bool Withdraw(double WithdrawAmount)
	{
		if (_Balance>=WithdrawAmount)
		{
			_Balance -= WithdrawAmount;
			Save();
			return true;
		}

		return false;
	}

	bool Transfer(clsBankClient& TransferTo, double Amount, string Username)
	{
		if (Withdraw(Amount))
		{
			TransferTo.Deposit(Amount);
			_LoadTransferLogLineToFile(TransferTo, Amount, Username);
			return true;
		}
		return false;
	}

	static vector<stTransferLog> GetTransferData()
	{
		return _LoadTransferLogData();
	}

};