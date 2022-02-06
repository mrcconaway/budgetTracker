#pragma once

#include "date.h"
#include "category.h"


class node
{
public:
    node(date da, category ca, double am, node* p = nullptr, node* n = nullptr ){
        d = da;
        c = ca;
        amount = am;
        prev = p; 
        next = n;
    }

    void add(date da, category ca, double am);

private:
    date d;
    category c;
    double amount;

    node* next;
    node* prev;
};