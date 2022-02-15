#include <iostream>
#include <fstream>
#include "node.h"
#include "BUDGET.h"
#include "date.h"
#include "month.h"
#include "list.h"

list::list()
{
    head = nullptr;
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
    if(fout.fail()){
        std::cout << "ERROR";
    }
    else{
        display(fout);
        fout.close();
    }
}

void make_dir(std::string sinp)
{
    std::string tmp = "";
    for(int i = 0; i = sinp.size()-1; ++i){
        tmp += sinp.size();
    }
}





// iterator functions
void list::set_cursor_forward()const
{
    
}

void list::set_cursor_backward()const
{

}
