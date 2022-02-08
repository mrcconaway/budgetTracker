#pragma once

#include <cstdlib>
#include "data"

class node
{
public:
    node();

private:
    data datafield;
    node* next;
    node* prev;
};