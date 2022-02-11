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
    void add_at_head(BUDGET binp);
    void remove(BUDGET target);

public:
    // iterators


public:
    // outputs
    void display(std::ostream& outs = std::cout)const;
    void display_node(std::ostream& outs = std::cout)const;



private:
    node* head;
    node* tail;
    const node* cursor_ptr;
};
