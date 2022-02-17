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
    l.load();

    l.display();

    return 1;
}
