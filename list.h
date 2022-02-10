#pragma once
#include <iostream>
#include "node.h"
#include "BUDGET.h"
#include "date.h"
#include "month.h"

class list
{
public:
    list();
public: // BIG 3
    ~list();
    list(const list& other);
    list& operator =(const list& other);
public:
    // mutators
    void add_item(BUDGET binp);

public:
    // accessor
    void display()const;


private:
    node* head;
    node* tail;
};