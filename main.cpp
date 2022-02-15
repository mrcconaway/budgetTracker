#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

std::string saveFile = "/Test/test.txt";

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


void make_dir(std::string sinp)
{
    cout << "make_dir called " << endl;    
    fs::create_directories(sinp.c_str());

}

string parse_Dir_and_File(std::string& dirInp){
    string tmp = "";
    int backslashCount;
    for(int i = 0; i < dirInp.size(); ++i){
        if(dirInp[i] == '/' || dirInp[i] == '\\'){
            backslashCount++;
            if( (backslashCount % 2) == 0 ){ // this is a directory
                make_dir(tmp);
                backslashCount++; // all future directories will only have one additional slash 
                                  // ie /test/"TEST/"test.txt
                tmp = "";
            }
        }
        else{
            tmp += dirInp[i];
        }
    }

    return tmp; // return file name
}



int main()
{
    
    string file = parse_Dir_and_File(saveFile);
    cout << file << endl;
    return 1;
}
