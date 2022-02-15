#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;

std::string saveFile = "TEST/TEST/test.txt";





void make_dir(std::vector<std::string> vinp)
{
    string dirTree = "";
    for(int i = 0; i < vinp.size(); ++i){
        dirTree += vinp[i];
        dirTree += "/";
    }  
    std::filesystem::create_directories(dirTree.c_str());
}

// given and a directory path and file name (ie dir1/dir2/..), it parses the directories and returns the file name
// Note: No directories should be given in the form /dir1/dir2/... so my logic could be reworked (the logic rn is designed so that
// the exception is the rule)
void parse_Dir(std::string dirInp){
    std::string tmp;
    std::vector<string> dir;
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
    if(dir.size() != 0)
        make_dir(dir); // create directory tree
    return;
}


void save()
{
    std::ofstream fout;
    fout.open(saveFile.c_str());
    if(fout.good()){
        fout << "TEST TEST HELLO HELLO TEST TEST" << std::endl;
        fout.close();
    }
    else{
        cout << "OH NO!";
    }
}

// defaults to "TEST/TEST/test.txt"
// NEED A WAY TO MAKE THESE CHANGES PERMANENT. LOOK INTO .conf files // 
//                                                                   //
void change_save_location(const std::string& s){
    parse_Dir(s);
    std::ofstream newOut;
    newOut.open(s.c_str());
    if(newOut.good()){
        std::ifstream  src(saveFile.c_str());
        newOut << src.rdbuf();
        saveFile = s;
    }
}

int main()
{

    parse_Dir(saveFile);
    save();
    string t1 = "here.txt";
    change_save_location(t1.c_str());

    return 1;
}
