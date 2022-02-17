#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include "node.h"
#include "BUDGET.h"
#include "date.h"
#include "month.h"
#include "list.h"

list::list()
{
    head = nullptr;
    parse_Dir(saveFile);
}

list::~list()
{
    node* rmptr;
    while( head != NULL ){
        rmptr = head;
        head = head->next();
        delete rmptr;
    }
}

list::list(const list& other)
{
    if(other.head == nullptr){ // empty list check
        head = nullptr;
    }
    else{
        head = new node( other.head-> data() );
        node* srcptr; 
        node* destptr;

        srcptr = other.head->next();
        destptr = head;

        while( srcptr != NULL){
            destptr->set_next( new node(srcptr->data()) );
            destptr = destptr->next();
            srcptr = srcptr->next();
        }
    }
}

list& list::operator =(const list& other)
{
    if(this == &other){ // check self assignment
        return *this;
    }

    node* rmptr;
    while( head != NULL ){
        rmptr = head;
        head = head->next();
        delete rmptr;
    }
    if(other.head == nullptr){ // empty list check
        head  = nullptr;
    }
    else{
        head = new node( other.head-> data() );
        node* srcptr; 
        node* destptr;

        srcptr = other.head->next();
        destptr = head;

        while( srcptr != NULL){
            destptr->set_next( new node(srcptr->data()) );
            destptr = destptr->next();
            srcptr = srcptr->next();
        }
    }
    return *this;
}


void list::add_item(BUDGET binp)
{
    if(head == nullptr){ // empty list
        head = new node(binp);
    }
    else{
        node* cursor = head;
        while(cursor-> next() != nullptr){
            cursor = cursor->next();
        }
        cursor->set_next( new node(binp, nullptr, cursor) );
    }
}

void list::add_at_head(BUDGET binp)
{

    node* cursor = head;
    head = new node(binp, cursor, nullptr); // head = new node(data, nextptr, prevptr)
    cursor->set_prev(head);
}

void list::remove(BUDGET target)
{
    node* forward = head;
    node* backward;
    if(head->data() == target){
        node* rmptr = head;
        head = head->next();
        delete rmptr;
    }
    else{
        while( forward != nullptr && !(forward->data() == target)){
            backward = forward;
            forward = forward->next();
        }
        if( forward != nullptr){
            backward->set_next( ( forward->next() ) );
            node* cursor = forward->next();
            cursor->set_prev(backward);
            delete forward;
        }
    }
}




void list::display(std::ostream& outs)const
{
    const node* ptr = head;
    while( ptr != nullptr){
        if( !(ptr->next() == nullptr) ){
            // outs << ptr->data();
            outs << ptr->data() << std::endl;
            ptr = ptr->next();
        }
        else{
            outs << ptr->data();
            ptr = ptr->next();
        }
    }
    return;
}

void list::display_node(std::ostream& outs, node* cursor)const
{
    if(cursor != nullptr){
        outs << cursor->data();
    }
    return;
}

void list::display_head(std::ostream& outs)const
{
    if(head != nullptr){
        outs << head->data();
    }
    return;
}

void list::display_tail(std::ostream& outs)const
{


    if(head == nullptr){ // empty list
        return;
    }
    else{
        node* cursor = head;
        while(cursor-> next() != nullptr){
            cursor = cursor->next();
        }
        outs << cursor->data();
    }
    return;
}

void list::save()const
{
    std::ofstream fout;
    fout.open(saveFile.c_str());
    if(fout.good()){
        display(fout);
        fout.close();
    }
    else{
        std::cout << "Error in save()!";
    }
}

// defaults to "TEST/TEST/test.txt"
// NEED A WAY TO MAKE THESE CHANGES PERMANENT. LOOK INTO .conf files // 
//                                                                   //
void list::change_save_location(const std::string& s)
{
    parse_Dir(s);
    std::ofstream newOut;
    newOut.open(s.c_str());
    if(newOut.good()){
        std::ifstream  src(saveFile.c_str());
        newOut << src.rdbuf();
        saveFile = s;
    }
}

void list::make_dir(std::vector<std::string> vinp)
{
    std::string dirTree = "";
    for(int i = 0; i < vinp.size(); ++i){
        dirTree += vinp[i];
        dirTree += "/";
    }  
    std::filesystem::create_directories(dirTree.c_str());
}

// given and a directory path and file name (ie dir1/dir2/..), it parses the directories and returns the file name
// Note: No directories should be given in the form /dir1/dir2/... so my logic could be reworked (the logic rn is designed so that
// the exception is the rule)
void list::parse_Dir(std::string dirInp)
{
    std::string tmp;
    std::vector<std::string> dir;
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

void list::load()
{
    std::ifstream finp;
    finp.open(saveFile.c_str());
    if(!finp.fail()){
        BUDGET tmp;
        finp >> tmp;




    }
}

// iterator functions
void list::set_cursor_forward()const
{
    
}

void list::set_cursor_backward()const
{

}
