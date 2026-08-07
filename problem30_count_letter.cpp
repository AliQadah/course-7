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

short countCharacter(string word,char character)
{
    short count=0;
    for(short i=0;i<word.length();i++)
    {

        if(word[i]==character)
        {
            count++;
        }

    }
    return count;
}

int main()
{
    string word=readWords();
    char character=readCharacter();
    cout<<"\nLetter \'"<<character<<"\'"<<" Count = "<<countCharacter(word,character);

}