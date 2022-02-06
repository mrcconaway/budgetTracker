#include "node.h"

void node::add(date da, category ca, double am){
    if( next == nullptr){
        next = prev = new Node(d);
    }
    else{
        prev->set_link( new Node (d) );
        prev = prev->link();
    }
}