#include<string>
#include<iostream>
using namespace std;
char readChar()
{
    char char1;
    cout<<"enter char:"<<endl;
    cin>>char1;
    return char1;
}

char invertCharacter(char char1)
{

    return(isupper(char1)?tolower(char1):toupper(char1));

}

int main()
{
    char char1=readChar();
    cout<<"\ncharacter after inver case:"<<endl;
    cout<<invertCharacter(char1);

}