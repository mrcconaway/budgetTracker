
#include "linkedList.h"
#include "node.h"
#include <cstdlib>

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

// Precondition: head_ptr is the head of a linked list
// Postcondition: The return value is a pointer to the first node containing the specified target 
// in its data field. If there is no such node, NULL is returned.   
node* linkedList::list_search(node* head_ptr, const node::value_type& target)
{
    node* cursor;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor->link()){
        if( target == cursor->data() ){
            return cursor;
        }
    }
    return NULL;
}

// Precondition: head_ptr is the head of a linked list
// Postcondition: The return value is a pointer to the first node containing the specified target 
// in its data field. If there is no such node, NULL is returned.   
const node* linkedList::list_search(const node* head_ptr, const node::value_type& target)
{
    const node* cursor;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor->link()){
        if( target == cursor->data()){
            return cursor;
        }
    }
    return NULL;
}

// Precondition: head_ptr is the head pointer of a linked lis, and position >0
// Postcondition: The pointer returned points to the node at the specified position
// in the list (The head is position 1,the next is position 2, and so on). If there is 
// no such position, then the NULL pointer is returned
node* linkedList::list_locate(node* head_ptr, size_t position)
{
    node* cursor = head_ptr;
    for(int i = 1; (i < position) &&  (cursor != NULL); ++i){
        cursor = cursor->link();
    }
    return NULL;
}

// Precondition: head_ptr is the head pointer of a linked lis, and position >0
// Postcondition: The pointer returned points to the node at the specified position
// in the list (The head is position 1,the next is position 2, and so on). If there is 
// no such position, then the NULL pointer is returned
const node* linkedList::list_locate(const node* head_ptr, size_t position)
{
    const node* cursor = head_ptr;
    for(int i = 1; (i < position) && (cursor != NULL); ++i){
        cursor = cursor->link();
    }
    return NULL;
}

// Precondition: source_ptr is the head of a linked list
// Postcondition: head_ptr and tail_ptr are the head and tail pointers
// for a new list that contains the same items as the list pointed to by 
// source_ptr.
// NOTE: If there is insufficient dynamic memory to create, then bad_alloc is thrown 
void linkedList::list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
{
    head_ptr = NULL;
    tail_ptr = NULL;
    // handle the case of an empty list
    if(source_ptr == NULL){
        return;
    }

    // Make the head node for the newly created list, and put data in it
    list_head_insert(head_ptr, source_ptr->data());
    tail_ptr = head_ptr;

    // Copy the rest of the nodes one at a time, adding at the tail of a new list
    source_ptr = source_ptr->link();
    while(source_ptr != NULL){
        list_insert(tail_ptr, source_ptr->data()); 
        tail_ptr = tail_ptr->link();
        source_ptr = source_ptr->link();
    }
}

// Preocondition: head_ptr is the head pointer of a linked list, 
// with at least one node
// Postcondition: The head node has been removed and returned to the heap;
// head_ptr is now the head pointer of the new, shorter linked list 
void linkedList::list_head_remove(node*& head_ptr)
{
    node* remove_ptr = head_ptr;
    head_ptr = head_ptr->link();
    delete remove_ptr;
}

// Precondition: previous_ptr points to a node in a linked list,
// and this is not the tail node of the list
// Postcondition: The node after previous_ptr has been removed from the linked list
void linkedList::list_remove(node* previous_ptr)
{
    node* remove_ptr;
    remove_ptr = previous_ptr->link();
    previous_ptr->set_link(remove_ptr->link());
    delete remove_ptr;
}

// Precondition: head_ptr is the head pointer of a linked list
// Postconditon: All nodes of the list have been deleted, and head_ptr is now NULL
void linkedList::list_clear(node*& head_ptr)
{
    while( head_ptr != NULL){
        list_head_remove(head_ptr);
    }
}
