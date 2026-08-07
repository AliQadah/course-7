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

int countEachWordInString(string Words)
{

    string space=" ";
    cout<<"your string word is : ";
    short pos=0;
    string sWord;
    short counter=0;
    while((pos=Words.find(space)) != std::string::npos)
    {

        sWord=Words.substr(0,pos);
        if(sWord!="")
        {
        counter++;
        }
        Words.erase(0,pos+space.length());
    }
    if(Words!="")
    {
        counter++;
    }
 return counter;
}
int main()
{
    string Words=readWords();
    cout<<"The number of words in your string is :"<<countEachWordInString(Words);
}