#pragma once

#include <iostream>
#include <iomanip>
#include <string>
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

    void input(std::istream& inp){
        std::string s; 
        getline(inp, s);
        std::string smonth = s.substr(0, 2);
        std::string sday = s.substr(3,2);
        std::string syear = s.substr(6,2);

        month = parse_month(smonth);
        day = stoi(sday);
        year = stoi(syear);
        
        return;
    }
    MONTH parse_month(std::string& input){
        int i = std::stoi(input);
        MONTH tmp = NONE;
        switch(i){
            case 1: 
                tmp = JANUARY;
                break;
            case 2: 
                tmp = FEBRUARY;
                break;
            case 3:
                tmp = MARCH;
                break;
            case 4:
                tmp = APRIL;
                break;
            case 5:
                tmp = MAY;
                break;
            case 6:
                tmp = JUNE;
                break;
            case 7:
                tmp = JULY;
                break;
            case 8:
                tmp = AUGUST;
                break;
            case 9:
                tmp = SEPTEMBER;
                break;
            case 10:
                tmp = OCTOBER;
                break;
            case 11:
                tmp = NOVEMBER;
                break;
            case 12:
                tmp = DECEMBER;
                break;
            case 0:
                tmp = NONE;
                break;
            default:
                tmp = NONE;
                break;
        }
        return tmp;
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
inline std::istream& operator >>(std::istream& inp, DATE& d){
    d.input(inp);
    return inp;
}
inline bool DATE::operator ==(const DATE& d2)const {
    return ( (year == d2.year) && (day == d2.day) && (month == d2.month) );
}
