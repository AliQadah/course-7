#include<string>
#include<iostream>
using namespace std;
string readWords()
{
    string Words;
    cout<<"please enter your string?"<<endl;
    getline(cin,Words);
    return Words;

}

char readCharacter()
{
    char char1;
    cout<<"please enter a character?"<<endl;
    cin>>char1;
    return char1;
}

short countCharacter(string word,char character,bool MacthCase=true)
{
    short count=0;
    for(short i=0;i<word.length();i++)
    {

        if(MacthCase)
        {
            if(word[i]==character)
                count++;
        }
        else 
        {
            if(tolower(word[i])==tolower(character))
                count++;
        }

    }
    return count;
}
char invertchar(char char1)
{

    return(isupper(char1)?tolower(char1):toupper(char1));

}
int main()
{
    string word=readWords();
    char character=readCharacter();
    cout<<"\nLetter \'"<<character<<"\'"<<" Count = "<<countCharacter(word,character);
    cout<<"\nLetter \'"<<character<<"\' Or "<<"\'"<<invertchar(character)<<"\' "<<"count = "<<countCharacter(word,character,false);

}