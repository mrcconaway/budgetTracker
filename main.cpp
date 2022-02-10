#include <istream>
#include "date.h"
#include "month.h"
#include "BUDGET.h"

int main()
{
    
    DATE d1(22, 5, APRIL);
    BUDGET t1;
    t1.set_amount(55.55);
    t1.set_category(HOUSING);
    t1.set_date(d1);

    t1.output(std::cout);

    BUDGET t2;
    t2.output(std::cout);
    t2 = t1;
    t2.output(std::cout);

    BUDGET t3;
    d1.set_year(22);
    t3.set_amount(200.00);
    t3.set_category(GAS);
    t3.set_date(d1);
    t3.output(std::cout);

    return 1;
}
