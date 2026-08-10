#include <iostream>
#include <string>
#include <vector>
using namespace std;
string replaceWordsUsingBuildInFunction(string s1,string stringToReplace,string sReplaceTo )
{

    short pos=s1.find(stringToReplace);
    while(pos!=std::string::npos)
    {
        s1=s1.replace(pos,stringToReplace.length(),sReplaceTo);
        pos=s1.find(stringToReplace);
    }
return s1;

}
int main()
{
string s1="welcome to Jordan , Jordan nice city";
cout<<s1<<endl;
cout<<"\nstring After Replace is :"<<endl;
cout<<replaceWordsUsingBuildInFunction(s1,"Jordan","USA");

}