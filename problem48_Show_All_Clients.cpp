#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
const string ClientFileName="Clients.txt";
struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};
vector <string> vSplit(string Line,string Delim)
{
    vector <string> vSplit;
    short pos=0;
    string sWord;
    while((pos=Line.find(Delim))!=std::string::npos)
    {
        sWord=Line.substr(0,pos);
        if(sWord!="")
        {
            vSplit.push_back(sWord);
        }
        Line.erase(0,pos+Delim.length());
    }
    if(Line!="")
    {
        vSplit.push_back(Line);
    }
    return vSplit;
}
stClient ConvertLineToRecord(string Line,string Delim="#//#")
{
    stClient Client;
    vector<string> vLine=vSplit(Line,Delim);
    Client.AccountNumber=vLine[0];
    Client.PinCode=vLine[1];
    Client.Name=vLine[2];
    Client.Phone=vLine[3];
    Client.AccountBalance=stod(vLine[4]);
    return Client;
}
vector <stClient> LoadDataFromFileToVector(string FileName)
{
 fstream File;
 stClient sClient;
  vector <stClient> vClient;
 File.open(FileName,ios::in);
 if(File.is_open())
 {
    string Line;
    while(getline(File,Line))
    {

        sClient=ConvertLineToRecord(Line);
        vClient.push_back(sClient);
    }
 } 
 return vClient;
}
void PrintClientRecord(stClient Client)
{
cout << "| " << setw(15) << left << Client.AccountNumber;
cout << "| " << setw(10) << left << Client.PinCode;
cout << "| " << setw(40) << left << Client.Name;
cout << "| " << setw(12) << left << Client.Phone;
cout << "| " << setw(12) << left << Client.AccountBalance;
}
void PrintFileData(vector <stClient> vClient)
{
    cout << "\n\t\t\t\t\tClient List (" << vClient.size() << ") Client(s).";
cout <<
"\n_______________________________________________________";
cout << "_________________________________________\n" << endl;
cout << "| " << left << setw(15) << "Accout Number";
cout << "| " << left << setw(10) << "Pin Code";
cout << "| " << left << setw(40) << "Client Name";
cout << "| " << left << setw(12) << "Phone";
cout << "| " << left << setw(12) << "Balance";
cout <<
"\n_______________________________________________________";
cout << "_________________________________________\n" << endl;
for (stClient Client : vClient)
{
PrintClientRecord(Client);
cout << endl;
}
cout <<
"\n_______________________________________________________";
cout << "_________________________________________\n" << endl;
}
 int main()
 {
    vector <stClient> vClient=LoadDataFromFileToVector(ClientFileName);
    PrintFileData(vClient);
 }