#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

std::string saveFile = "/Test/Test1/Test2/test.txt";

void save()
{
    std::ofstream fout;
    fout.open(saveFile.c_str());
    if(fout.fail()){
        std::cout << "ERROR";
    }
    else{
        fout << "TEST TEST TEST TEST" << std::endl;
        fout.close();
    }
}


void make_dir(std::vector<std::string> vinp)
{
    string dirTree = "";
    cout << "make_dir called " << endl; 
    for(int i = 0; i < vinp.size(); ++i){
        cout << vinp[i] << endl; 
        dirTree += vinp[i];
        dirTree += "/";
    }  
    cout << dirTree << endl;
    fs::create_directories(dirTree.c_str());

}

string parse_Dir_and_File(std::string& dirInp){
    string tmp;
    vector<string> dir;
    int count = 0;

    for(int i = 0; i < dirInp.size(); ++i){
        if(dirInp[i] == '/' || dirInp[i] == '\\'){
            count++;
            if( (count % 2) == 0){ // this is a directory
                dir.push_back(tmp);
                // cout << "directory: " << tmp << endl;
                tmp = "";
                count++;
            }
        }
        else{
            tmp += dirInp[i];
        }
    }
    // cout << "filename: " << tmp << endl;
    make_dir(dir);
    return tmp;
}

int main()
{


    string file = parse_Dir_and_File(saveFile);


    return 1;
}
