#pragma once
#include "BUDGET.h"
#include "date.h"
#include "month.h"


class node
{
public:
    node(BUDGET bInit = BUDGET(), node* nInit = nullptr, node* pInit = nullptr){
        budget = bInit;
        nfield = nInit;
        pfield = pInit;
    }
public:
    //Accessors
    const BUDGET data()const { return budget; }
    const node* next()const { return nfield; }
    const node* prev()const { return pfield; }  
    node* next(){ return nfield; }
    node* prev(){ return pfield; } 

public:
    // Mutators
    void set_data(BUDGET binp){ budget = binp; }
    void set_next(node* ninp){ nfield = ninp; }
    void set_prev(node* pinp){ pfield = pinp;}

private:
    BUDGET budget;  
    node* nfield;
    node* pfield;
};