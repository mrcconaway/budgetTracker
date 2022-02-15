#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

std::string saveFile = "Hello/Hello1/Hello2/test.txt";

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
    for(int i = 0; i < vinp.size(); ++i){
        cout << vinp[i] << endl;
        dirTree += vinp[i];
        dirTree += "/";
    }  
    fs::create_directories(dirTree.c_str());

}

// given and a directory path and file name (ie dir1/dir2/) 
string parse_Dir_and_File(std::string& dirInp){
    string tmp;
    vector<string> dir;
    int count = 0;
    if(dirInp[0] != '/' || dirInp[0] != '/'){ // in case a path is given in the form dir0/dir1/file.txt
                                                  // converts it to the equivalent /dir0/dir1/file.txt so the logic works correctly
        dirInp = "/" + dirInp;
    }
    for(int i = 0; i < dirInp.size(); ++i){
        if(dirInp[i] == '/' || dirInp[i] == '\\'){
            count++;
            if( (count % 2) == 0){ // this is a directory
                dir.push_back(tmp);
                tmp = "";
                count++;
            }
        }
        else{
            tmp += dirInp[i];
        }
    }
    make_dir(dir);
    return tmp;
}

int main()
{


    string file = parse_Dir_and_File(saveFile);


    return 1;
}
