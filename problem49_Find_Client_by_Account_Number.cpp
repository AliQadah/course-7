#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const string ClientFileName = "Clients.txt";
const string Delim = "#//#";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> vSplit(string Line, string Delim)
{
    vector<string> vSplit;
    size_t pos = 0;
    string sWord;

    while ((pos = Line.find(Delim)) != string::npos)
    {
        sWord = Line.substr(0, pos);

        if (sWord != "")
        {
            vSplit.push_back(sWord);
        }

        Line.erase(0, pos + Delim.length());
    }

    if (Line != "")
    {
        vSplit.push_back(Line);
    }

    return vSplit;
}

stClient ConvertLineToRecord(string Line, string Delim = "#//#")
{
    stClient Client;
    vector<string> vLine = vSplit(Line, Delim);

    Client.AccountNumber = vLine[0];
    Client.PinCode = vLine[1];
    Client.Name = vLine[2];
    Client.Phone = vLine[3];
    Client.AccountBalance = stod(vLine[4]);

    return Client;
}

vector<stClient> LoadDataFromFileToVector(string FileName)
{
    fstream File;
    stClient Client;
    vector<stClient> vClients;

    File.open(FileName, ios::in);

    if (File.is_open())
    {
        string Line;

        while (getline(File, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }

        File.close();
    }

    return vClients;
}

string ReadClientAccountNumber()
{
    string AccountNumber;

    cout << "\nPlease enter Account Number: ";
    cin >> AccountNumber;

    return AccountNumber;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code: " << Client.PinCode;
    cout << "\nName: " << Client.Name;
    cout << "\nPhone: " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
{
    vector<stClient> vClients =
        LoadDataFromFileToVector(ClientFileName);

    for (stClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }

    return false;
}

int main()
{
    stClient Client;
    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number ("
             << AccountNumber << ") is Not Found!\n";
    }

    return 0;
}