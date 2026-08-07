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

    return(isupper(char1)?true:false);

}
int countUpperWord(string word)
{
    //string word2;
    int count=0;
    for(int i=0;i<word.length();i++)
    {
        if(invertchar(word[i]))
        {
            count++;
        }
    }
    return count;
}
int countLowerWord(string word)
{
    //string word2;
    int count=0;
    for(int i=0;i<word.length();i++)
    {
        if(invertchar(word[i])==false)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string word=readWords();
    cout<<"\nstring Length="<<word.length()<<endl;
    cout<<"capital latters count is "<<countUpperWord(word)<<endl;
    cout<<"small letter count is :"<<countLowerWord(word)<<endl;

}