#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
void LoadFileDataToVector(vector <string>& vFileContent,string FileName)
{
    fstream File;
    File.open(FileName,ios::in);
    if(File.is_open())
    {

        string Line;
        while(getline(File,Line))
        {
            vFileContent.push_back(Line);
        }
        File.close();
    }
}

int main()
{
    vector <string> vFileContent;
    LoadFileDataToVector(vFileContent,"Myfile.txt");
    for(string &Line:vFileContent)
    {
        cout<<Line<<endl;
    }
}