#include <iostream>
#include "month.h"


class date
{
public: // BIG 3! 
    // constructor
    date(int y = 0, int d = 0, MONTH m = NONE){ year = y; day = d; month = m; }
    
    // copy constructor
    // date& operator =(const date& other){
    //     if(this == &other){
    //         return this;
    //     }
    //     month = other.month;
    //     day = other.day;
    //     year = other.year;
    //     return this;
    // }
    
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
        std::cout << get_day() << " " << get_year() << " " << get_month() << std::endl;
    }

private:
    int year;
    int day;
    MONTH month;
};