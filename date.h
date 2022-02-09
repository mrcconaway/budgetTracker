#include "month.h"


class date
{
    date(int y = 0, int d = 0, MONTH m = 0){ year = y; day = d; month = m; }

    // mutator
    void set_day(int d);
    void set_year(int y);
    void set_month(MONTH m);

    // accessor
    const int get_day();
    const int get_year();
    const MONTH get_month();


private:
    int year;
    int day;
    MONTH month;
};

// mutator
void set_day(int d){ d = day; }
void set_year(int y){ year = y; }
void set_month(MONTH m){ month = m; }

// accessor
const int get_day(){ return day; }
const int get_year() { return year; }
const MONTH get_month(){ return MONTH; }