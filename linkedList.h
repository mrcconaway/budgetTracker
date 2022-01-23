#pragma once


#include "node.h"

class linkedList
{
public:
    // list manipulation 
    size_t list_length(const node* head_ptr);
    void list_insert(node* previous_ptr, const node::value_type& entry);
    void list_head_insert(node*& head_ptr, const node::value_type& entry);


private:
    node list;
};