#include <istream>
#include "date.h"
#include "month.h"


int main()
{
    date test1;
    test1.set_day(1);
    test1.set_year(21);
    test1.set_month(FEBRUARY);

    date test2;
    test2.set_day(2);
    test2.set_year(22);
    test2.set_month(JANUARY);
    
    date test3 = test1;
    test1.display();
    test2.display();
    test3.display(); 
    return 1;
}
