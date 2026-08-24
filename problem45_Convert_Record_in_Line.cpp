#include <iostream>
#include <string>
using namespace std;
struct stClient
{

    string AccountNumber;
    string PinCode;
    string Name;
    string phone;
    double AccountBalance;

};

stClient ReadClient()
{

    stClient Client;
    cout<<"Enter Account Number?"<<endl;
    getline(cin,Client.AccountNumber);
    cout<<"Enter PinCode?"<<endl;
    getline(cin,Client.PinCode);
    cout<<"Enter Name?"<<endl;
    getline(cin,Client.Name);
    cout<<"Enter Phone?"<<endl;
    getline(cin,Client.phone);
    cout<<"Enter AccountBalance?"<<endl;
    cin>>Client.AccountBalance;
    return Client;
}

string ConverRecordToLne(stClient Client,string Delim="#//#")
    {
        string stClientRecord="";
        stClientRecord+=Client.AccountNumber+Delim;
         stClientRecord+=Client.PinCode+Delim;
         stClientRecord+=Client.Name+Delim;
         stClientRecord+=Client.phone+Delim;
         stClientRecord+=to_string(Client.AccountBalance);
        return stClientRecord;    
    }
int main()
{
    cout<<"please Enter Client Data: "<<endl;
    stClient Client=ReadClient();
    cout<<"\n\nClient Record for saving is :"<<endl;
    cout<<ConverRecordToLne(Client)<<endl;
}