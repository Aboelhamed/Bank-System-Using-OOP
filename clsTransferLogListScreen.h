#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <vector> 

using namespace std;

class clsTransferLogListScreen : protected clsScreen
{
private:

    static void PrintTransferLogRecordLine(clsBankClient::stTransferLog& TransferLog)
    {

        cout << "| " << setw(22) << left << TransferLog.Date;
        cout << "| " << setw(6) << left << TransferLog.SourceAccNumber;
        cout << "| " << setw(6) << left << TransferLog.DisAccNumber;
        cout << "| " << setw(14) << left << TransferLog.Amount;
        cout << "| " << setw(14) << left << TransferLog.SourceBalance;
        cout << "| " << setw(14) << left << TransferLog.DisBalance;
        cout << "| " << setw(14) << left << TransferLog.Username;
    }

public :

    static void ShowTransferLogList()
    {

        vector<clsBankClient::stTransferLog>vTransferLogs = clsBankClient::GetTransferData();

        string Title = "\t Transfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogs.size()) + ") Transfer Log";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(22) << "Date";
        cout << "| " << left << setw(6) << "S.Account";
        cout << "| " << left << setw(6) << "D.Account";
        cout << "| " << left << setw(14) << "Amount";
        cout << "| " << left << setw(14) << "S.Balance";
        cout << "| " << left << setw(14) << "D.Balance";
        cout << "| " << left << setw(14) << "Username";
        cout << "\n" << setw(8) << left << "" << "_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogs.size() == 0)
        {
            cout << "\t\t\t\tNo TransferLogs Available In the System!";
        }
        else
        {
            for (clsBankClient::stTransferLog& TransferLog : vTransferLogs)
            {
                cout << setw(8) << left << "";
                PrintTransferLogRecordLine(TransferLog);
                cout << endl;
            }
            cout << setw(8) << left << "" << "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
        }
    }


};

