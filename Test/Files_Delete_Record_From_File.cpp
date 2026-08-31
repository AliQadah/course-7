#include<iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
void LoadDataFromFileToVector(string FileName,vector <string> &vFileContent)
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
void DeletRecordFromVector(vector <string>&vFileContent,string DeleteRecord)
{
    for(int i=0;i<vFileContent.size();i++)
    {
        if(vFileContent[i]==DeleteRecord)
        {
            vFileContent[i]="";
        }

    }
}
void LoadDataFromVectorToFile(string FileName,vector <string> &vFileContent,string DeleteRecord)
{
  DeletRecordFromVector(vFileContent,DeleteRecord);
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
vector <string> vFileContent;
LoadDataFromFileToVector("Myfile.txt",vFileContent);
LoadDataFromVectorToFile("Myfile.txt",vFileContent,"Ali");
}