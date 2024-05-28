#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base(){}
Base::~Base(){}

Base *  generate(void){
    srand(static_cast<unsigned int>(time(NULL)));
    int i = rand() % 3 + 1;

}

void    identify(Base *p);
void    identify(Base &p);
