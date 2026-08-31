#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void PrintFileContent(string FileName)
{
    fstream File;
    File.open(FileName,ios::in);
    if(File.is_open())
    {

        string Line;
        while(getline(File,Line))
        {
            cout<<Line<<endl;
        }

        File.close();
    }

}
int main()
{
    PrintFileContent("Myfile.txt");
}