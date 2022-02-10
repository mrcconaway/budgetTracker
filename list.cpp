#include <iostream>
#include "node.h"
#include "BUDGET.h"
#include "date.h"
#include "month.h"
#include "list.h"

list::list()
{
    head = nullptr;
    tail = nullptr;
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
        head = tail = nullptr;
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
        tail = destptr;
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
        head = tail = nullptr;
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
        tail = destptr;
    }
    return *this;
}


void list::add_item(BUDGET binp)
{
    if(head == nullptr){
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




void list::display()const
{
    const node* ptr = head;
    while( ptr != nullptr){
        std::cout << ptr->data() << std::endl;
         ptr = ptr->next();
    }
}
