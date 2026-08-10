#include <iostream>
#include<string>
using namespace std;
string readWords()

{
    string Words;
    cout<<"please enter your string?"<<endl;
    getline(cin,Words);
    return Words;

}

string trimLeft(string Text)
{
    
    for(int i=0;i<Text.length();i++)
    {
        if(Text[i]!=' ')
        {
            return Text.substr(i,Text.length()-i);
        }
    }
    return "";
}
string trimRight(string Text)
{
    
    for(int i=Text.length()-1;i>=0;i--)
    {
        if(Text[i]!=' ')
        {
            return Text.substr(0,i+1);
        }
    }
    return "";
}
string trim(string Text)
{
    return(trimLeft(trimRight(Text)));
}
int main()
{
    string Text="   Ali Qadah   ";
    cout<<" trim left:"<<trimLeft(Text)<<endl;
    cout<<" trim Right:"<<trimRight(Text)<<endl;
    cout<<" Trim:"<<trim(Text);
}
