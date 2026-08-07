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
void printFirstLetterOfEachWord(string Words)
{
    bool isFirstLetter=true;
    for(int i=0;i<Words.length();i++)
    {
        if(Words[i] != ' ' && isFirstLetter)
        {
            cout<<Words[i]<<endl;
        }
        isFirstLetter=(Words[i]==' ' ? true:false);
    }
}

int main()
{
    printFirstLetterOfEachWord(readWords());
}