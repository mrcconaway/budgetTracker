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
        outs << "\n" << display_category() << "\n"; 
        return; 
        }

    void input(std::istream& ins){

        std::string svalue; // for the leading $
        std::string scategory; // for the date
        // get amount
        getline(ins, svalue);
        std::cout << svalue << std::endl; 
        svalue.erase(0,1);
        std::cout << svalue << std::endl; 
        amount = std::stof(svalue);

        // get date
        ins >> d;
        
        // get category
        // Look into using unordered_maps!
        getline(ins, scategory);
        if(scategory == "GROCERY"){
            c = GROCERY;
        }
        else if(scategory == "GAS"){
            c = GAS;
        }
        else if(scategory == "ENTERTAINMENT"){
            c = ENTERTAINMENT;
        }
        else if(scategory == "UTILITIES"){
            c = UTILITIES;
        }
        else if(scategory == "SAVING"){
            c = SAVING;
        }
        else if(scategory == "HOUSING"){
            c = HOUSING;
        }
        else{
            c = UNKNOWN;
        }


        return;
    }

public:
    bool operator ==(const BUDGET& b2)const;

private:
    float amount;
    DATE d;
    CATEGORY c;
};


inline std::ostream& operator <<(std::ostream& out, const BUDGET& b){
    b.output(out);
    return out;
}

inline std::istream& operator >>(std::istream& ins, BUDGET& b)
{
    b.input(ins);
    return ins;
}

inline bool BUDGET::operator ==(const BUDGET& b2)const{
    return ( (amount == b2.amount) && (d == b2.d) && (c == b2.c) );
}