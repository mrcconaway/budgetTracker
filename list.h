#pragma once
#include <iostream>
#include "node.h"
#include "BUDGET.h"
#include "date.h"
#include "month.h"

class list
{
public: // BIG 3
    list();

private:
    node* head;
    node* tail;
};