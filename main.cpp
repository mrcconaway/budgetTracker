#include <iostream>
#include <fstream>
#include "date.h"
#include "month.h"
#include "BUDGET.h"
#include "node.h"
#include "list.h"

int main()
{
    list l;

    DATE d1(22, 5, APRIL);
    BUDGET t1;
    t1.set_amount(55.55);
    t1.set_category(HOUSING);
    t1.set_date(d1);
    l.add_item(t1);
    // t1.output(std::cout);

    BUDGET t2;
    // t2.output(std::cout);
    l.add_item(t2);
    t2 = t1;
    l.add_item(t2);

    // t2.output(std::cout);

    BUDGET t3;
    d1.set_year(22);
    t3.set_amount(200.00);
    t3.set_category(GAS);
    t3.set_date(d1);
    // t3.output(std::cout);

    l.add_at_head(t3);
    BUDGET t0;
    l.add_item(t0);

    l.save();


    return 1;
}
