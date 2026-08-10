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


int main()
{
    vector <string> vString={"Ahmed","Ali","Fadi","Dawood","Fuad"};
    cout<<"vector after join string :"<<endl;
    cout<<joinString(vString," ");
}