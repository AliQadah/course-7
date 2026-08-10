#include <iostream>
#include <string>
#include <vector>
using namespace std;
string joinString(vector<string>vString,string Delim)
{

    string s1="";
    for(string& Text:vString)
    {
        s1=s1+Text+Delim;
    }
    return s1.substr(0,s1.length()-Delim.length());
}

string joinString(string arr[],int arrLength,string Delim)
{

    string s1="";
    for(int i=0;i<arrLength;i++)
    {
        s1=s1+arr[i]+Delim;
    }
    return s1.substr(0,s1.length()-Delim.length());
}


int main()
{
    vector <string> vString={"Ahmed","Ali","Fadi","Dawood","Fuad"};
    string arr[]={"Ahmed","Ali","Fadi","Dawood","Fuad"};
    int Length=sizeof(arr)/sizeof(arr[0]);
    cout<<"vector after join string :"<<endl;
    cout<<joinString(vString," ");

     cout<<"\narr after join string :"<<endl;
     cout<<joinString(arr,Length," ");

}