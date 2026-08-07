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

short countVowel(string Words)
{
    short count=0;
    for(short i=0;i<Words.length();i++)
    {

        if(isVowel(Words[i]))
            count++;

    }
    return count;
}

int main()
{
    string words=readWords();
    cout<<"Number of Vowel is "<<countVowel(words)<<endl;
  
}
