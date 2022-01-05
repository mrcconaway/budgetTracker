#pragma once

#include <string>
#include "date.h"
#include "month.h"


class category{

public:
    enum type{
        GROCERY = 1,
        UTILITIES = 2,
        TRANSPORTATION = 3,
        MEDICAL = 4,
        OTHER = 5,
        INCOME = 6
    };
    void setCategory(type input);

private:
    type c;

};