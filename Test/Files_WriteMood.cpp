#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream Myfile;
    Myfile.open("Myfile.txt",ios::out);

    if(Myfile.is_open())
    {
        Myfile<<"HI iam Ali"<<endl;
        Myfile<<"Iam Ahmaed"<<endl;
        Myfile.close();
    }
}