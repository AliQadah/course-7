#include <iostream>
#include <string>
#include <vector>
using namespace std;
string readWords()
{
    string Words;
    cout<<"please enter your string?"<<endl;
    getline(cin,Words);
    return Words;

}
vector <string>  vSplit(string Words,string Delim)
{
    vector <string> vSplit;
    short pos=0;
    string sWord;
    while((pos=Words.find(Delim))!=std::string::npos)
    {

       sWord=Words.substr(0,pos);
        if(sWord!="")
        {
             vSplit.push_back(Words.substr(0,pos));
        }
        Words.erase(0,pos+Delim.length());
    }

    if(Words!="")
    {
        vSplit.push_back(Words);
    }
    return vSplit;
}

void printSplitString(vector <string> vSplit)
{
    short Tokens=vSplit.size();
    cout<<"Tokens = "<<Tokens<<endl;
    for(string words:vSplit)
    {
        cout<<words<<endl;
    }
}

int main()
{
   vector <string> vString;
   vString=vSplit(readWords()," ");
   cout<<"Tokens = "<<vString.size()<<endl;
   for(string& s:vString)
   {
    cout<<s<<endl;
   }

}