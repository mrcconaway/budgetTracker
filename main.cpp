#include "date.h"
#include "month.h"


int main()
{
    date test1;
    test1.set_day(1);
    test1.set_year(21);
    test1.set_month(FEBRUARY);

    date test2;
    test1.set_day(2);
    test1.set_year(22);
    test1.set_month(JANUARY);
    
    return 1;
}
