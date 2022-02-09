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

    t1.display();

    return 1;
}
