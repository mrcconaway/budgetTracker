#pragma once
#include "BUDGET.h"
#include "date.h"
#include "month.h"


class node
{
public:
    node(BUDGET bInit = BUDGET(), node* nInit = nullptr, node* pInit = nullptr){
        budget = bInit;
        next = nInit;
        prev = pInit;
    }
public:
    //Accessors
    const BUDGET data(){ return budget; }
    const node* nLink(){ return next; }
    const node* pLink(){ return prev; }

public:
    // Mutators
    void set_data(BUDGET binp){ budget = binp; }
    void set_nLink(node* ninp){ next = ninp; }
    void set_pLink(node* pinp){ prev = pinp;}

private:
    BUDGET budget;  
    node* next;
    node* prev;
};