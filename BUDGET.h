#pragma once
#include "date.h"
#include "category.h"

class BUDGET
{
public:
    // mutators
    void set_amount(float inp);
    void set_date(DATE inp);
    void set_category(CATEGORY inp);

    // accessors
    const float get_amount();
    const DATE get_date();
    const CATEGORY get_category();

private:
    float amount;
    DATE d;
    CATEGORY c;
};

// mutators
void BUDGET::set_amount(float inp){ amount = inp; }
void BUDGET::set_date(DATE inp){ d = inp; }
void BUDGET::set_category(CATEGORY inp){ c = inp; }

// accessors
const float BUDGET::get_amount(){ return amount; }
const DATE BUDGET::get_date(){ return d; }
const CATEGORY BUDGET::get_category(){ return c; }