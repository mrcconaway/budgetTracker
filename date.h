#pragma once

#include "month.h"
class date{

public:
    date(){
        m = DEFAULT;
        d = 0;
        y = 0000;
    }
    // mutators
    void setdate(month mInput, int dInput, int yInput);
    void setMonth(month input);
    void setDay(int input);
    void setYear(int input);

    date operator+(const date& d){
        date tmp;
        tmp.m = this->m;
        tmp.d = this->d;
        tmp.y = this->y;
        return tmp;
    }

private:
    month m;
    int d;
    int y;
};