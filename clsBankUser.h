#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtility.h"


using namespace std;

class clsBankUser : public clsPerson
{
private :

	enum enMode {EmptyMode, UpdateMode, AddMode};
	enMode _Mode;
	string _Username;
	string _Password;
	short _Permissions = 0;		// 0 0 0 0 0 0 0 0
	bool _IsMarkDelete = false;
	struct stLoginRegisterData;

	static clsBankUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string>Users = clsString::SplitString(Line, Seperator);
		return clsBankUser(enMode::UpdateMode, Users[0], Users[1], Users[2], Users[3], Users[4], clsUtility::DecryptText((Users[5])), stoi(Users[6]));
	}

	static stLoginRegisterData _ConvertLineToUserRegisterRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterData UserRegister;
		vector<string>vTransfer = clsString::SplitString(Line, Seperator);
		UserRegister.Date = vTransfer[0];
		UserRegister.Username = vTransfer[1];
		UserRegister.Password = clsUtility::DecryptText(vTransfer[2]);
		UserRegister.Permissions = stoi(vTransfer[3]);

		return UserRegister;
	}

	static string _ConvertUserObjectToLine(clsBankUser User, string Seperator = "#//#")
	{
		string S1 = "";

		S1 = User.FirstName + Seperator;
		S1 += User.LastName + Seperator;
		S1 += User.Email + Seperator;
		S1 += User.Phone + Seperator;
		S1 += User.Username + Seperator;
		S1 += clsUtility::EncryptText((User.Password)) + Seperator;
		S1 += to_string(User.getPermissions());

		return S1;

	}

	string _ConvertUserLoginRegisterToLine(string Seperator = "#//#")
	{
		string S1 = "";

		S1 = clsDate::DateDetailsToString(clsDate()) + Seperator;
		S1 += Username + Seperator;
		S1 += clsUtility::EncryptText(Password)+Seperator;
		S1 += to_string(Permissions);

		return S1;

	}

	static clsBankUser _GetEmptyUserObject()
	{
		return clsBankUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankUser> _LoadUserData()
	{
		vector<clsBankUser>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);		//Read Only
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				vUsers.push_back(_ConvertLineToUserObject(Line));

			}
			MyFile.close();
		}
		return vUsers;
	}

	static vector<stLoginRegisterData> _LoadUserRegisterData()
	{
		vector<stLoginRegisterData>vUserRegister;
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);		//Read Only
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				vUserRegister.push_back(_ConvertLineToUserRegisterRecord(Line));

			}
			MyFile.close();
		}
		return vUserRegister;
	}

	void _LoadLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);		//Read and Write
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
		}
		MyFile.close();
	}

	void _SaveUsersData(vector<clsBankUser>vUsers)
	{
		fstream MyFile;
		MyFile.open("users.txt", ios::out);		//Write Only
		if (MyFile.is_open())
		{
			for (clsBankUser& user : vUsers)
			{
				if (!user._IsMarkDelete)
				{
					MyFile << _ConvertUserObjectToLine(user) << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsBankUser>vUsers = _LoadUserData();

		for (clsBankUser& user : vUsers)
		{
			if (user.Username==Username)
			{
				user = *this;
				break;
			}
		}
		_SaveUsersData(vUsers);
	}

	void _AddNewUser()
	{
		_LoadLineToFile(_ConvertUserObjectToLine(*this));
	}


public :
	
	static struct stLoginRegisterData
	{
		string Date;
		string Username;
		string Password;
		short Permissions;
	};

	clsBankUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string Username, string Password, short Permissions)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_Username = Username;
		_Password = Password;
		_Permissions = Permissions;
	}

	enum enPermissions { ShowClientsList = 1, AddNewClient = 2, DeleteClient = 4, UpdateClient = 8, FindClient = 16, Transactions = 32, ManageUser = 64, UserRegisterList = 128, CurrencyExchange=256, All = -1 };

	void setUsername(string Username)		//set property
	{
		_Username = Username;
	}
	
	string getUsername()		//get property
	{
		return _Username;
	}

	__declspec(property(get = getUsername, put = setUsername))string Username;

	void setPassword(string Password)		//set property
	{
		_Password = Password;
	}
	
	string getPassword()		//get property
	{
		return _Password;
	}

	__declspec(property(get = getPassword, put = setPassword))string Password;

	void setPermissions(short Permissions)
	{
		_Permissions = Permissions;
	}

	short getPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = getPermissions, put = setPermissions))short Permissions;

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsBankUser Find(string Username, string Password, bool WithPassword)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);		//Read Only
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankUser user = _ConvertLineToUserObject(Line);
				if (user.Username == Username && (!WithPassword || user.Password == Password))
				{
					MyFile.close();
					return user;
				}
			}
			MyFile.close();
			return _GetEmptyUserObject();
		}
	}

	static clsBankUser Find(string Username)
	{
		return Find(Username, "", false);
	}

	static clsBankUser Find(string Username, string Password)
	{
		return Find(Username, Password, true);
	}

	static bool IsUserExist(string Username)
	{
		clsBankUser user = Find(Username);
		return (!user.IsEmpty());
	}

	enum enSaveResult{SaveFalidEmptyObject, SaveSuccessfully, SaveFaildUserExist};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return enSaveResult::SaveFalidEmptyObject;
			
		case enMode::UpdateMode:
			_Update();
			return enSaveResult::SaveSuccessfully;

		case enMode::AddMode:
			if (!IsUserExist(_Username))
			{
				_AddNewUser();
				return enSaveResult::SaveSuccessfully;
			}
			else
			{
				return enSaveResult::SaveFaildUserExist;
			}
			
		}
	}

	bool Delete()
	{
		vector<clsBankUser>vUsers = _LoadUserData();

		for (clsBankUser& user : vUsers)
		{
			if (user.Username == Username)
			{
				user._IsMarkDelete = true;
				break;
			}
		}
		_SaveUsersData(vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}

	static clsBankUser GetAddNewUserObject(string Username)
	{
		return clsBankUser(enMode::AddMode, "", "", "", "", Username , "", 0);
	}

	static vector<clsBankUser> GetUserList()
	{
		return _LoadUserData();
	}

	static vector<stLoginRegisterData> GetUserRegisterList()
	{
		return _LoadUserRegisterData();
	}

	bool CheckUserPermissions(enPermissions permission)
	{
		if ((permission & this->Permissions) == permission)
		{
			return true;
		}
		return false;
	}

	void LoadLineToUserLoginRegisterFile()
	{
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);		//Read Only
		if (MyFile.is_open())
		{
			MyFile << _ConvertUserLoginRegisterToLine() << endl;
		}
		MyFile.close();
	}

};

