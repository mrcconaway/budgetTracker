#pragma once

#include <iostream>
#include <iomanip>
#include "month.h"

class DATE
{
public: // BIG 3! 
    // constructor
    DATE(int y = 0, int d = 0, MONTH m = NONE){ year = y; day = d; month = m; }
    
    
public:
    // mutator
    void set_day(int d){ d = day; }
    void set_year(int y){ year = y; }
    void set_month(MONTH m){ month = m; }

    // accessor
    const int get_day()const { return day; }
    const int get_year()const { return year; }
    const MONTH get_month()const { return month; }
    
    void output(std::ostream& outs)const{
        outs << std::setw(2) << std::setfill('0') << get_month() << "/";
        outs << std::setw(2) << std::setfill('0') << get_day() << "/";
        outs << std::setw(2) << std::setfill('0') << get_year() << " ";
        return;
    }

public:
    bool operator == (const DATE& d2)const;

private:
    int year;
    int day;
    MONTH month;
};
inline std::ostream& operator <<(std::ostream& out, const DATE& d){
    d.output(out);
    return out;
}
inline bool DATE::operator ==(const DATE& d2)const {
    return ( (year == d2.year) && (day == d2.day) && (month == d2.month) );
}
