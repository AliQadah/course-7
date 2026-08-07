#include<iostream>
#include<string>
using namespace std;
string readWords()
{
    string Words;
    cout<<"please enter your string?"<<endl;
    getline(cin,Words);
    return Words;

}
char isVowel(char character)
{
    character=tolower(character);
    return((character=='a')||(character=='e')||(character=='i')||(character=='o')||(character=='u'));

}

void printVowelInString(string Words)
{
    string words2;
    for(short i=0;i<Words.length();i++)
    {

        if(isVowel(Words[i]))
        cout<<Words[i]<<" ";

    }
}

int main()
{
    string words=readWords();
    printVowelInString(words);
  
}
