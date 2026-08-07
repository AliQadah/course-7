#include<string>
#include<iostream>
using namespace std;

string readWords()
{
    string Words;
    cout<<"enter words"<<endl;
    getline(cin,Words);
    return Words;

}
string upperOfFirstLetterOfEachWord(string Words)
{
    bool isFirstLetter=true;
    for(int i=0;i<Words.length();i++)
    {
        if(Words[i] != ' ' && isFirstLetter)
        {
           Words[i]=toupper(Words[i]);
        }
        isFirstLetter=(Words[i]==' ' ? true:false);
    }
    return Words;
}

int main()
{
    cout<<upperOfFirstLetterOfEachWord(readWords());
}