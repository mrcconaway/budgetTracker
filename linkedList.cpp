
#include "linkedList.h"
#include "node.h"
#include <cstdlib>

// The Big 3! //

// Deconstructor
linkedList::~linkedList()
{
    node* rmptr;
    while ( head != NULL){
        rmptr = head;
        head = head->link();
        delete rmptr;
    }
}

// Constructor
linkedList::linkedList()
{
    head = NULL;
}

// copy constructor
linkedList::linkedList(const linkedList& other)
{
    if ( other.head == NULL){
        head = NULL;
    }
    else{
        head = new node(other.head->data());
        node* srcptr; // source pointer
        node* destptr; // destination pointer
        
        srcptr = other.head->link();
        destptr = head;

        while( srcptr != NULL){
            destptr->set_link(new node(srcptr->data()));
            destptr = destptr->link();
            srcptr = srcptr->link();
        }
    }
}

linkedList& linkedList::operator =(const linkedList& other)
{
    if(this == &other){ // check for self assignment
        return *this;
    }

    // clear the list being assinged new values (destructor code)
    node* rmptr;
    while ( head != NULL){
        rmptr = head;
        head = head->link();
        delete rmptr;
    }

    // assign new values (constructor code)
    if ( other.head == NULL){
        head = NULL;
    }
    else{
        head = new node(other.head->data());
        node* srcptr; // source pointer
        node* destptr; // destination pointer
        
        srcptr = other.head->link();
        destptr = head;

        while( srcptr != NULL){
            destptr->set_link(new node(srcptr->data()));
            destptr = destptr->link();
            srcptr = srcptr->link();
        }
    }

}



