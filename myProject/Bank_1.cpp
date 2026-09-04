#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
// Material
const string Delim = "#//#";
const string FileName = "Client1.txt";
struct sClient
{
    string AccountNumber;
    string PinCode;
    string ClientName;
    string Phone;
    double AccountBalance;
    bool MarkDelete = false;
};
enum eMainMenu
{
    showClientList = 1,
    addNewClient = 2,
    deleteClient = 3,
    updateClientInfo = 4,
    findClient = 5,
    exitProgram = 6
};
// Logic
bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient &Client)
{   
    // vClients = ReadClientFromFile(FileName);

    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }

    return false;
}
vector<string> vSplit(string Words, string Delim)
{
    vector<string> vSplit;
    short pos = 0;
    string sWord;
    while ((pos = Words.find(Delim)) != std::string::npos)
    {

        sWord = Words.substr(0, pos);
        if (sWord != "")
        {
            vSplit.push_back(Words.substr(0, pos));
        }
        Words.erase(0, pos + Delim.length());
    }

    if (Words != "")
    {
        vSplit.push_back(Words);
    }
    return vSplit;
}
string ConvertRecordToLine(sClient Client,string Delim)
{
    
    string Line=Client.AccountNumber+Delim;
    Line+=Client.PinCode+Delim;
    Line+=Client.ClientName+Delim;
    Line+=Client.Phone+Delim;
    Line+=to_string(Client.AccountBalance);
    return Line;
}
sClient ConvertLineToRecord(string Line, string Delim="#//#")
{
    sClient Client;
    vector<string> vLine = vSplit(Line, Delim);
    Client.AccountNumber = vLine[0];
    Client.PinCode = vLine[1];
    Client.ClientName = vLine[2];
    Client.Phone = vLine[3];
    Client.AccountBalance = stod(vLine[4]);
    return Client;
}
vector<sClient> ReadClientFromFile(string FileName)
{
    vector<sClient> vClient;
    sClient Client;
    fstream File;
    File.open(FileName, ios::in);
    if (File.is_open())
    {
        string Line;
        while (getline(File, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClient.push_back(Client);
        }
        File.close();
    }

    return vClient;
}
void SaveVectorDataToFile(string FileName,vector <sClient>vClient)
{
    fstream File;
    File.open(FileName,ios::out);
    if(File.is_open())
    {

        string Line;
        for(sClient c:vClient)
        {
            if(c.MarkDelete==false)
            {
            Line=ConvertRecordToLine(c,Delim);
            File<<Line<<endl;
            }
        }   

        File.close();
    }

}
bool MarkClientDelete(string AccountNumber,vector<sClient>&vClient)
{

for(sClient &c:vClient)
{
    if(c.AccountNumber==AccountNumber)
    {
        c.MarkDelete=true;
        return true;

    }
    
}
return false;
}   
sClient ChangeClientRecord(string AccountNumber)
{
   sClient Client;
    Client.AccountNumber=AccountNumber;
    cout<<"Enter Pin Code?";
    getline(cin>>ws,Client.PinCode);
    cout<<"Enter Name?";
    getline(cin,Client.ClientName);
    cout<<"Enter Phone?";
    getline(cin,Client.Phone);
    cout<<"Enter AccountBalance?";
    cin>>Client.AccountBalance;

    return Client;
}
// ScreenShow
void GoBackToMainMenu()
{
    cout << "\n\nPress anu key to go back to Main Menu "<<endl;
    system("pause>0");

}
sClient AddClient(string AddNewAccountNumber)
{
    sClient NewClient;
    NewClient.AccountNumber=AddNewAccountNumber;
    cout<<"Enter Pin Code?";
    getline(cin>>ws,NewClient.PinCode);
    cout<<"Enter Name?";
    getline(cin,NewClient.ClientName);
    cout<<"Enter Phone?";
    getline(cin,NewClient.Phone);
    cout<<"Enter AccountBalance?";
    cin>>NewClient.AccountBalance;
    NewClient.MarkDelete=false;
    return NewClient;
}
void PrintClient(sClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(40) << Client.ClientName;
    cout << "| " << left << setw(12) << Client.Phone;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}
void ShowClientList(vector<sClient> &vClient)
{
    cout << "\t\t\tClient List (" << vClient.size() << ") Client(s)." << endl;
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    for (sClient &c : vClient)
    {
        PrintClient(c);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    GoBackToMainMenu();
    

}
void AddNewClient(vector <sClient> vClient)
{
    string AddNewAccountNumber;
    char MoreClient;
    bool IsClientPresent=false;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"\t Add New Clients Screen "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    do
    {
        cout<<"Adding New Client:"<<endl;
        cout<<"\n Enter Account Number?";
        getline(cin>>ws,AddNewAccountNumber);
        for(int i=0;i<vClient.size();i++)
        {
            if (vClient[i].AccountNumber==AddNewAccountNumber)
            {
                IsClientPresent=true;
                break;
            }
        }
        if(!IsClientPresent)
        {
            vClient.push_back(AddClient(AddNewAccountNumber));
        }
        else
        {
            cout<<"Client with ["<<AddNewAccountNumber<<"] already exists, Enter another Account Number?";
                 getline(cin>>ws,AddNewAccountNumber);
                 vClient.push_back(AddClient(AddNewAccountNumber));
        }
        SaveVectorDataToFile(FileName,vClient);
        cout<<"Client Add successfully ,do you want to add more clients? Y/N?";
        cin>>MoreClient;
    }while(MoreClient=='Y'||MoreClient=='y');
    GoBackToMainMenu();

}
void PrintClientCard(sClient Client)
{

    cout<<"The following are the Client details:"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"Account Number:"<<Client.AccountNumber<<endl;
    cout<<"Account Code  :"<<Client.PinCode<<endl;
    cout<<"Name          :"<<Client.ClientName<<endl;
    cout<<"Phone         :"<<Client.Phone<<endl;
    cout<<"Account Balance:"<<Client.AccountBalance<<endl;
    cout<<"------------------------------------"<<endl;

}
void DeleteClient(vector <sClient> &vClient)
{

    string AccountNumber;
    sClient Client;
    char Choose='n';
    cout<<"-----------------------------------"<<endl;
    cout<<"\tDelete Client Screen"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"\nPlease enter Account Number";
    getline(cin>>ws,AccountNumber);
    if(!FindClientByAccountNumber(AccountNumber,vClient,Client))
    {
        cout<<"Client With Account Number ("<<AccountNumber<<") is Not Found!"<<endl;
        GoBackToMainMenu();
    }
    else
    {
        PrintClientCard(Client);
        cout<<"Are you sure You Want delete this Client? y/n?"<<endl;
        cin>>Choose;
        if(Choose=='Y'||Choose=='y')
        {
            MarkClientDelete(AccountNumber,vClient);
            SaveVectorDataToFile(FileName,vClient);
            vClient=ReadClientFromFile(FileName);
            cout << "Client Deleted Successfuly" << endl;
        }
    }
        
}
void UpdateClientInfo(vector <sClient> &vClient)
{
     string AccountNumber;
    sClient Client;
    char Choose='n';
    cout<<"-----------------------------------"<<endl;
    cout<<"\tUpdate Client Screen"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"\nPlease enter Account Number";
    getline(cin>>ws,AccountNumber);
    if(!FindClientByAccountNumber(AccountNumber,vClient,Client))
    {
        cout<<"Client With Account Number ("<<AccountNumber<<") is Not Found!"<<endl;
        GoBackToMainMenu();
    }
    else
    {
        PrintClientCard(Client);
        cout<<"Are you sure You Want Update this Client? y/n?"<<endl;
        cin>>Choose;
        if(Choose=='Y'||Choose=='y')
        {
            for(sClient &c:vClient)
            {
                if(c.AccountNumber==AccountNumber)
                {
                c=ChangeClientRecord(AccountNumber);
                break;
                }
            }
            SaveVectorDataToFile(FileName,vClient);
            cout << "Client Updated Successfuly" << endl;
        }
    }
}
void FindClient(vector <sClient>vClient)
{
     string AccountNumber;
    sClient Client;
     cout<<"-----------------------------------"<<endl;
    cout<<"\tFind Client Screen"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"\nPlease enter Account Number";
    getline(cin>>ws,AccountNumber);
    if(!FindClientByAccountNumber(AccountNumber,vClient,Client))
    {
        cout<<"Client With Account Number ("<<AccountNumber<<") is Not Found!"<<endl;
        GoBackToMainMenu();
    }
    else
    {
        PrintClientCard(Client);
        GoBackToMainMenu();
    }
}
void Exit()
{
     cout<<"-----------------------------------"<<endl;
    cout<<"\tProgram Ends :-)"<<endl;
    cout<<"-----------------------------------"<<endl;
}
void MainMenuScreen(vector<sClient> &vClient)
{
    eMainMenu Menu;
    short choose;
    cout << "===========================================" << endl;
    cout << "\t\tMain Menue Screen" << endl;
    cout << "===========================================" << endl;
    cout << "[1] Show Client List." << endl;
    cout << "[2] Add New Client." << endl;
    cout << "[3] Delete Client." << endl;
    cout << "[4] Update Client Info." << endl;
    cout << "[5] Find Client." << endl;
    cout << "[6] Exit." << endl;
    cout << "===========================================" << endl;
    cout << "Choose What do you want to do? [1 to 6]?" << endl;
    cin >> choose;
    Menu = (eMainMenu)choose;
    switch (Menu)
    {
    case showClientList:
        ShowClientList(vClient);
        break;
        case addNewClient:
        AddNewClient(vClient);
        break;
        case deleteClient:
        DeleteClient(vClient);
        break;
        case updateClientInfo:
        UpdateClientInfo(vClient);
        break;
        case findClient:
        FindClient(vClient);
        break;
        case exitProgram:
        Exit();
        break;
        
    }
}
int main()
{
    vector<sClient> vClient;
    vClient = ReadClientFromFile(FileName);
    MainMenuScreen(vClient);
}