#pragma once
#include <iostream>
#include <string>
#include "date.h"
#include "CATEGORY.h"


class BUDGET
{
public:
    BUDGET(float aInit = 0 , DATE dInit = DATE(), CATEGORY cInit = UNKNOWN  ){
        set_amount(aInit);
        set_date(dInit);
        set_category(cInit);
    }

public:
    // mutators
    void set_amount(float inp){ amount = inp; }
    void set_date(DATE inp){ d = inp; }
    void set_category(CATEGORY inp){ c = inp; }

    // accessors
    const float get_amount()const { return amount; }
    const DATE get_date()const { return d; }
    const CATEGORY get_category()const { return c; }

    const std::string display_category()const {
        std::string c_str;
        switch(get_category()){
            default: 
                c_str = "UNKOWN";
                break;
            case GROCERY:
                c_str = "GROCERY";
                break;
            case GAS:
                c_str = "GAS";
                break;
            case ENTERTAINMENT:
                c_str = "ENTERTAINMENT";
                break;
            case UTILITIES:
                c_str = "UTILITIES";
                break;
            case SAVING:
                c_str = "SAVING";
                break;
            case HOUSING:
                c_str = "HOUSING";
                break;
        }
        return c_str;
    } 

    void output(std::ostream& outs)const{
        outs << "$" << amount << "\n";
        d.output(outs); 
        outs << "\n" << display_category() << "\n\n"; 
        return; }

private:
    float amount;
    DATE d;
    CATEGORY c;
};


inline std::ostream& operator <<(std::ostream& out, const BUDGET& b){
    b.output(out);
    return out;
}