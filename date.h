#include "month.h"


class date
{
public: // BIG 3! 
    // constructor
    date(int y = 0, int d = 0, MONTH m = NONE){ year = y; day = d; month = m; }
    
    // copy constructor
    date& date::operator =(const date& other){
        if(this == &other){
            return *this;
        }
    
    // code of the destructor
    // code of the copy constructor

        return *this;
    }



public:
    // mutator
    void set_day(int d){ d = day; }
    void set_year(int y){ year = y; }
    void set_month(MONTH m){ month = m; }

    // accessor
    const int get_day(){ return day; }
    const int get_year(){ return year; }
    const MONTH get_month(){ return month; }
    


private:
    int year;
    int day;
    MONTH month;
};