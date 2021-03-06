#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include "node.h"
#include "BUDGET.h"
#include "date.h"
#include "month.h"

class list
{
public:
    list();
public: // BIG 3
    ~list();
    list(const list& other);
    list& operator =(const list& other);
public:
    // mutators
    void add_item(BUDGET binp);
    void add_at_head(BUDGET binp);
    void remove(BUDGET target);

public:
    // iterators
    void set_cursor_forward()const;
    void set_cursor_backward()const;

public:
    // outputs
    void display(std::ostream& outs = std::cout)const;
    void display_head(std::ostream& outs = std::cout)const;
    void display_tail(std::ostream& outs = std::cout)const;
    void display_node(std::ostream& outs = std::cout, node* cursor = nullptr )const;

public:
    // i/o to file
    void save()const;
    void change_save_location(const std::string& s);
    void make_dir(std::vector<std::string> vinp);
    void parse_Dir(std::string dirInp);

    void load();


private:
    node* head;
    std::string saveFile = "Data/data.txt";
};
