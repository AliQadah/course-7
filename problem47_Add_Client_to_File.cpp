#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
stClient ReadClient()
{
    stClient Client;
    cout<<"Enter Account Number?"<<endl;
    getline(cin>>ws,Client.AccountNumber);
    cout<<"Enter PinCode?"<<endl;
    getline(cin>>ws,Client.PinCode);
    cout<<"Enter Name?"<<endl;
    getline(cin>>ws,Client.Name);
    cout<<"Enter Phone ?"<<endl;
    getline(cin>>ws,Client.Phone);
    cout<<"Enter Account Balance?"<<endl;
    cin>>Client.AccountBalance;
    return Client;
}

string ConvertRecordToLine(stClient Client,string Delim="#//#")
{
    string Line="";
    Line+=Client.AccountNumber+Delim;    
    Line+=Client.PinCode+Delim;
    Line+=Client.Name+Delim;
    Line+=Client.Phone+Delim;
    Line+=to_string(Client.AccountBalance);
    return Line;
}
void AddDataLineToFile(string ClientFileName,string DataLine)
{
    fstream myFile;
    myFile.open(ClientFileName, ios::out|ios::app);
    if (myFile.is_open())
    {
        myFile<<DataLine<<endl;

        myFile.close();
    }
}

void AddNewClient()
{
    stClient Client;
    Client=ReadClient();
    AddDataLineToFile(ClientFileName,ConvertRecordToLine(Client));
}
void AddClient()
{
    char AddMore='Y';
    do
    {
    cout<<"Adding New Client\n:"<<endl;
    
    AddNewClient();
    cout<<"Client Added Successfuly , do you want more Client?"<<endl;
    cin>>AddMore;
    }while(toupper(AddMore)=='Y');
}
int main()
{
    AddClient();
}