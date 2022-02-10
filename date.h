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
    const int get_day(){ return day; }
    const int get_year(){ return year; }
    const MONTH get_month(){ return month; }
    
    void display(){
        std::cout << std::setw(2) << std::setfill('0') << get_month() << "/";
        std::cout << std::setw(2) << std::setfill('0') << get_day() << "/";
        std::cout << std::setw(2) << std::setfill('0') << get_year() << " ";
    }

private:
    int year;
    int day;
    MONTH month;
};