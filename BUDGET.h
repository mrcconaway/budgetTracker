#pragma once
#include <iostream>
#include "date.h"
#include "CATEGORY.h"


class BUDGET
{
public:
    // mutators
    void set_amount(float inp){ amount = inp; }
    void set_date(DATE inp){ d = inp; }
    void set_category(CATEGORY inp){ c = inp; }

    // accessors
    const float get_amount(){ return amount; }
    const DATE get_date(){ return d; }
    const CATEGORY get_category(){ return c; }

    const void display(){std::cout << amount << " "; d.display(); std::cout <<  c << std::endl; }

private:
    float amount;
    DATE d;
    CATEGORY c;
};


