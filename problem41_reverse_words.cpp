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

string reverseWordsInString(string s1)
{
string s2="";
vector <string> vString;
vString=vSplit(s1," ");
vector <string>::iterator iter=vString.end();
while(iter !=vString.begin())
{
    --iter;
    s2=s2+*iter+" ";
}

s2=s2.substr(0,s2.length()-1);
return s2;
}

int main()
{
string s1=readWords();
cout<<"string After Reverse is "<<endl;
cout<<"\n"<<reverseWordsInString(s1);

}