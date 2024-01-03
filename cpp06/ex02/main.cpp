#include "Base.hpp"

int main(void)
{
    Base* one = generate();
    Base& ref_one = *one; 
    identify(one);
    identify(ref_one);

    delete one;
}