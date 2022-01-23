#include <cstdlib>

class node
{
public:
    // TYPEDEF
    typedef double value_type;

    node(const value_type& init_data = value_type(), node* init_link = nullptr)
    {
        data_field = init_data; next = init_link;
    }

    // members functions to set data and link field
    void set_data(const value_type& new_data) { data_field = new_data; }
    void set_link(node* new_link) { next = new_link; }

    // constant member function to retrive current data
    value_type data()const { return data_field; }

    // two slightly different member functions to retreive current link
    const node* link() const { return next; }
    node* link() { return next; }


private:
    value_type data_field;
    node* next;
};