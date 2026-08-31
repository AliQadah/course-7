#include <iostream>
#include <fstream>
using namespace std;
int main()
{

    fstream Myfile;
    Myfile.open("Myfile.txt", ios::out|ios::app);
    if(Myfile.is_open())
    {

        Myfile<<"Ali the best"<<endl;
        Myfile<<"Alawi"<<endl;
        Myfile<<"how are you"<<endl;


        Myfile.close();
    }
    

    

}