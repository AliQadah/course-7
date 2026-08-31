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
    bool MarkDelete = false;
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

stClient ConvertLineToRecord (string Line, string Delim)
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
string ConverRecordToLine(stClient Client,string Delim="#//#")
    {
        string stClientRecord="";
        stClientRecord+=Client.AccountNumber+Delim;
         stClientRecord+=Client.PinCode+Delim;
         stClientRecord+=Client.Name+Delim;
         stClientRecord+=Client.Phone+Delim;
         stClientRecord+=to_string(Client.AccountBalance);
        return stClientRecord;    
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
            Client = ConvertLineToRecord(Line,Delim);
            vClients.push_back(Client);
        }

        File.close();
    }

    return vClients;
}
vector<stClient> SaveClientDataToFile(string ClientFileName, vector<stClient> vClient)
{
    fstream File;

    File.open(ClientFileName, ios::out);
    string DataLine;
    if (File.is_open())
    {

        for (stClient c : vClient)
        {

            if (c.MarkDelete == false)
            {

                DataLine = ConverRecordToLine(c, Delim);
                File << DataLine << endl;
            }
        }
        File.close();
    }
    return vClient;
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

bool FindClientByAccountNumber(string AccountNumber, vector<stClient> vClients, stClient &Client)
{   
     vClients = LoadDataFromFileToVector(ClientFileName);

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
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient> &vClient)
{

    for (stClient &c : vClient)
    {

        if (c.AccountNumber == AccountNumber)
        {
            c.MarkDelete = true;
            return true;
        }
    }
    return false;
}
bool DeletedClientByAccountNumber(string AccountNumber, vector<stClient> &vClient)
{
    stClient Client;
    char Input = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClient, Client))
    {
        PrintClientCard(Client);
        cout << "Are You Sure you want delete this Client? (y or n)?";
        cin >> Input;
        if (Input == 'Y' || Input == 'y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClient);
            SaveClientDataToFile(ClientFileName, vClient);
            // refresh
            vClient = LoadDataFromFileToVector(ClientFileName);
            cout << "Client Deleted Successfuly" << endl;
            return true;
        }
    }
    else
    {
        cout << "Client with Account Number (" << AccountNumber << ") is Not Found" << endl;
        return false;
    }
}
int main()
{
    vector<stClient> vClient = LoadDataFromFileToVector(ClientFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeletedClientByAccountNumber(AccountNumber, vClient);

    return 0;
}