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
string lowerOfFirstLetterOfEachWord(string Words)
{
    bool isFirstLetter=true;
    for(int i=0;i<Words.length();i++)
    {
        if(Words[i] != ' ' && isFirstLetter)
        {
           Words[i]=tolower(Words[i]);
        }
        isFirstLetter=(Words[i]==' ' ? true:false);
    }
    return Words;
}

int main()
{
    cout<<lowerOfFirstLetterOfEachWord(readWords());
    return 0;
}