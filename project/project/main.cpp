#include <iostream>
#include ""

using namespace std;

int main()
{
    Forest* f = Forest::get_instance(10, 20, 30, 20);
    f->live();
    Forest::clear_instance();
    return 0;
}