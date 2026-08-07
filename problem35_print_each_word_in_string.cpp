#include <string>
#include <iostream>
using namespace std;
string readWords()
{
    string Words;
    cout<<"please enter your string?"<<endl;
    getline(cin,Words);
    return Words;

}

void printEachWordInString(string Words)
{

    string space=" ";
    cout<<"your string word is : "<<endl;
    short pos=0;
    string sWord;

    while((pos=Words.find(space)) != std::string::npos)
    {

        sWord=Words.substr(0,pos);
        if(sWord!="")
        {
        cout<<sWord<<endl;
        }
        Words.erase(0,pos+space.length());
    }
    if(Words!="")
    {
        cout<<Words<<endl;
    }
 
}
int main()
{
    string Words=readWords();
    printEachWordInString(Words);
}

//other way to solove problem:
/*
#include <string>
#include <iostream>
using namespace std;
string readWords()
{
    string Words;
    cout<<"please enter your string?"<<endl;
    getline(cin,Words);
    return Words;

}
void printEachWordInString(string Words)
{

    for(int i=0;i<Words.length();i++)
    {
        string letter="";
        if(Words[i]!=' ')
        {
        letter=letter+Words[i];
        cout<<letter;
        }
        else
        {
            cout<<endl;
        }

    }
}
int main()
{
    string Words=readWords();
    printEachWordInString(Words);
}
    */