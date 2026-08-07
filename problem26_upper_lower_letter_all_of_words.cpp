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
string upperOfLetterOfEachWord(string Words)
{
    //bool isFirstLetter=true;
    for(int i=0;i<Words.length();i++)
    {
           Words[i]=toupper(Words[i]);
        
      //  isFirstLetter=(Words[i]==' ' ? true:false);
    }
    return Words;
}
string lowerOfLetterOfEachWord(string Words)
{
    //bool isFirstLetter=true;
    for(int i=0;i<Words.length();i++)
    {
      
           Words[i]=tolower(Words[i]);
        
     //   isFirstLetter=(Words[i]==' ' ? true:false);
    }
    return Words;
}

int main()
{
    string words=readWords();
    cout<<"\nthe upper of all lettres is : "<<endl;
    cout<<upperOfLetterOfEachWord(words)<<endl;

    cout<<"\nthe lower of all lettres is : "<<endl;
    cout<<lowerOfLetterOfEachWord(words)<<endl;
    return 0;
}