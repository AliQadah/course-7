#include <iostream>
#include <string>
#include <vector>
using namespace std;
string RemovePunct(string s1)
{
    string s2 = "";
    for (short i = 0; i < s1.length(); i++)
    {

        if (!ispunct(s1[i]))
        {
            s2 += s1[i];
        }
    }
    return s2;
}
int main()
{
    string s1 = "Hello I'm ali .i love programming .";
    cout << RemovePunct(s1);
}