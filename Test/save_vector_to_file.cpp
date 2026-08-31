#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void SaveVectorToFile(string FileName , vector <string> vFileContent )
{
    fstream File;
    File.open(FileName,ios::out);
    if(File.is_open())
    {
         
        for(string &Line:vFileContent)
        {

            if(Line!="")
            {
                File<<Line<<endl;
            }

        }
        File.close();
    }
}
int main()
{
    vector <string> vFileContent={"Ali","Mohammed","Omar","Ahmed","Tasneem"};
    SaveVectorToFile("MyFile.txt",vFileContent);
}