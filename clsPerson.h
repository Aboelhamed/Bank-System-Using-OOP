#pragma once

#include <iostream>

using namespace std;

class clsPerson
{
private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    void setFirstName(string FirstName)   //set property
    {
        _FirstName = FirstName;
    }
    
    string getFirstName()   //get property
    {
        return _FirstName;
    }

    __declspec(property(get = getFirstName, put = setFirstName))string FirstName;

    void setLastName(string LastName)   //set property
    {
        _LastName = LastName;
    }
    
    string getLastName()   //get property
    {
        return _LastName;
    }
    
    __declspec(property(get = getLastName, put = setLastName))string LastName;

    string getFullName()
    {
        return _FirstName + " " + _LastName;
    }

    void setEmail(string Email)   //set property
    {
        _Email = Email;
    }
    
    string getEmail()   //get property
    {
        return _Email;
    }
    
    __declspec(property(get = getEmail, put = setEmail))string Email;

    void setPhone(string Phone)   //set property
    {
        _Phone = Phone;
    }
    
    string getPhone()   //get property
    {
        return _Phone;
    }

    __declspec(property(get = getPhone, put = setPhone))string Phone;

};
