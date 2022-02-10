#include <iostream>
#include "date.h"
#include "month.h"
#include "BUDGET.h"
#include "node.h"
#include "list.h"

int main()
{
    DATE d1;
    DATE d2(12,0,APRIL);
    DATE d3(7,35,NOVEMBER);

    BUDGET b1(88, d1, UNKNOWN);
    BUDGET b2(55, d2, GAS);
    BUDGET b3 = b1;

    list l;
    l.add_item(b1);
    l.add_item(b2);
    l.add_item(b3);
    l.display();

    std::ofstream fout;
    fout.open("test1.txt".c_str());



    return 1;
}
