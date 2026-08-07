#include<iostream>
#include<string>
using namespace std;
char readCharacter()
{
    char char1;
    cout<<"please enter a character?"<<endl;
    cin>>char1;
    return char1;
}

char isVowel(char character)
{
    character=tolower(character);
    return((character=='a')||(character=='e')||(character=='i')||(character=='o')||(character=='u'));

}

int main()
{
    char character=readCharacter();
    if(isVowel(character))
    cout<<"YES Letter \'"<<character<<"\' is Vowl"<<endl;
    else
     cout<<"No Letter \'"<<character<<"\' is NOT Vowl"<<endl;
}
