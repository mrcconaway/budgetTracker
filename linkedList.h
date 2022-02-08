#pragma once


#include "node.h"
#include <cstdlib>

class linkedList
{
public: 
    linkedList();
public:
    // implementation

public: // The Big 3! 
    ~linkedList(); // Deconstructor
    linkedList(const linkedList& other); // Constructor
    linkedList& operator =(const linkedList& other);


private:
    node* head;
};