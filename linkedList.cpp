#include "linkedList.h"
#include "node.h"

// Precondition: head_ptr is the head of a linked list
// Postcondition: the value of the returned is the number of nodes in the linked list
// library facilities used: ctsdlib
size_t linkedList::list_length(const node* head_ptr)
{
    size_t ans = 0;
    for(const node* cursor = head_ptr; cursor != nullptr; cursor = cursor->link() ){
        ++ans;
    }
    return ans;
}

// Precondition: previous_ptr points to a node in a linked list
// Postcondition: a new node containin the given entry has been added 
// after the node that p points to
// NOTE: of there is insufficienct dynamic memory for a new node,
// then bad_alloc will be thrown 
void linkedList::list_insert(node* previous_ptr, const node::value_type& entry)
{
    node* insert_ptr = new node(entry, previous_ptr->link());
    previous_ptr->set_link(insert_ptr);
}

// Precondition: head_ptr is the head of a linked list
// Postcondition: A new node containing the given entry has been added at 
// the head of the list; head_ptr now points to the head of the new, longer
// linked list
// NOTE: of there is insufficienct dynamic memory for a new node,
// then bad_alloc will be thrown 
void linkedList::list_head_insert(node*& head_ptr, const node::value_type& entry)
{
    head_ptr = new node(entry, head_ptr);
}

