#pragma once


#include "node.h"
#include <cstdlib>

class linkedList
{
public:
    // list manipulation 
    size_t list_length(const node* head_ptr);
    void list_insert(node* previous_ptr, const node::value_type& entry);
    void list_head_insert(node*& head_ptr, const node::value_type& entry);
    void list_head_remove(node*& head_ptr);
    void list_remove(node* previous_ptr);
    void list_clear(node*& head_ptr);

    // list accessors
    node* list_search(node* head_ptr, const node::value_type& target);
    const node* list_search(const node* head_ptr, const node::value_type& target);
    node* list_locate(node* head_ptr, size_t position);
    const node* list_locate(const node* head_ptr, size_t position);

    // copy a list
    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);

private:
    node list;
};