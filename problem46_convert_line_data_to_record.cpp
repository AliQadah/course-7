#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct stClient
{

    string AccountNumber;
    string PinCode;
    string Name;
    string phone;
    double AccountBalance;

};
string ReadLine()
{
    string Line;
    cout<<"please enter your Line"<<endl;
    getline(cin,Line);
    return Line;
}
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
    Client.phone=vLine[3];
    Client.AccountBalance=stod(vLine[4]);
    return Client;
}
void PrintClientRecord(stClient Client)
{

cout<<"Account Number is "<<Client.AccountNumber<<endl;
cout<<"PinCode is "<<Client.PinCode<<endl;
cout<<"Name is "<<Client.Name<<endl;
cout<<"Phone is "<<Client.phone<<endl;
cout<<"AccountBalance is "<<Client.AccountBalance<<endl;

}
int main()
{
    string Line="A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.0000";
    PrintClientRecord(ConvertLineToRecord(Line));
}