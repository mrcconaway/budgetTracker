#include <cstdlib>
#include "node.h"
#include "date.h"

// BIG 3! // 

node::node(node* nInit = nullptr, node* pInit = nullptr, float a = 0.0, DATE d = DATE())
{
    next = nInit;
    prev = pInit;

}