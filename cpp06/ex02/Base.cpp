#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define RESET       "\033[0m\033[0m"

void    identify(Base* p)
{
    std::cout << BOLDGREEN << std::setw(30) << "identifing Base Pointer ";
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "type is A" << RESET <<std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "type is B" << RESET <<std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "type is C" << RESET <<std::endl;
    else
        std::cout << "It's not A, B or C" << std::endl;
}

void    identify(Base& p)
{
    std::cout << BOLDRED << std::setw(30) << "identifing Base Referance ";
    try 
    {
        A & temp =  dynamic_cast<A &>(p);
        (void)temp;
        std::cout << "type is A" << RESET <<std::endl;
    }
    catch (std::exception & e){
        try 
        {
            B & temp =  dynamic_cast<B &>(p);
            (void)temp;
            std::cout << "type is B" << RESET <<std::endl;
        }
        catch (std::exception & e){
            try 
            {
                C & temp =  dynamic_cast<C &>(p);
                (void)temp;
                std::cout << "type is C" << RESET <<std::endl;
            }
            catch (std::exception & e){
                
            };
        };
    };
    
}

Base *  generate(void){
    srand(static_cast<unsigned int>(time(NULL)));
    int i = rand() % 3 + 1;

    switch (i) {
        case 1:
            std::cout << "made A" << std::endl;
            return (new A);
        case 2:
            std::cout << "made B" << std::endl;
            return (new B);
        case 3:
            std::cout << "made C" << std::endl;
            return (new C);
    }
    std::cerr << "something went wrong" << std::endl;
    return NULL;
}

Base::Base(){}

Base::~Base(){}
