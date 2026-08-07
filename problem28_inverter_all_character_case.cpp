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

char invertchar(char char1)
{

    return(isupper(char1)?tolower(char1):toupper(char1));

}
string checkWord(string word)
{
    //string word2;
    for(int i=0;i<word.length();i++)
    {
        word[i]=invertchar(word[i]);
    }
    return word;
}
int main()
{
    string word=readWords();
    cout<<"\nstring after invert all character case:"<<endl;
    cout<<checkWord(word);

}