#include <string>
#include <iostream>
#include "date.h"
#include "month.h"

void date::setdate(month mInput, int dInput, int yInput)
{
    setMonth(mInput);
    setDay(dInput);
    setYear(yInput);
}


void date::setMonth(month input)
{
    m = input;
}

void date::setDay(int input)
{
    // while(input < 1 || input > 31){
    //     std::cout << "Invalid Day Input:\n Re-Input day: ";
    //     std::cin >> input;
    //     if(std::cin.fail() || !std::isdigit(input) ){
    //         std::cin.clear();
    //         std::cin.ignore();
    //         input = 0;
    //     }
    // }
    d = input;
}

void date::setYear(int input)
{
    // std::string tmp = std::to_string(input);
    // while(tmp.size() != 4){ // year has 4 digits
    //     std::cout << "Invalid Year Input:\n Re-Input Year (YYYY): ";
    //     std::cin >> input;
    //     if(std::cin.fail() || !std::isdigit(input) ){
    //         std::cin.clear();
    //         std::cin.ignore();
    //         input = 0;
    //     }
    // }
    y = input;
}