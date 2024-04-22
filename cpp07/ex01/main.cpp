#include <iostream>
#include "iter.hpp"

void printNum(int & num){
	std::cout << num ;
}

void testNum(int & num){
	if (num % 3) num = 0;
	std::cout << num ;
} 

int main(){
	int a[10] = { 1,2,3,4,5,6,7,8,9,10};
	
	::iter(a, 10, printNum);
	std::cout << "\nprintNum executed" << std::endl;
	std::cout << "------------------" <<std::endl;
	
	
	::iter(a, 10, testNum);
	std::cout << "\ntestNum executed" << std::endl;
	std::cout << "-----------------" <<std::endl;
	

}