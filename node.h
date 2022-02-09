#pragma once

#include <cstdlib>
#include "date.h"
#include "month.h"

class node
{
public:
    node(node* n = nullptr, node* p = nullptr, float a = 0.0, DATE d = DATE());
    

private:
    BUDGET budget;
private:
    node* next;
    node* prev;
};