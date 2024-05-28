#include <iostream>
#include <time.h>
#include "iter.hpp"

void printNum(int & num){
	std::cout << num ;
}

void testNum(int & num){
	if (num % 3) num = 0;
	std::cout << num ;
}

void initTime(time_t& p){
	p = time_t(time(NULL));
}

void printTime(time_t& p){
	if (!p) return;
	std::cout << p << std::endl;
}

int main(){
	int a[10] = { 1,2,3,4,5,6,7,8,9,10};
	
	::iter(a, 10, printNum);
	std::cout << "\nprintNum executed" << std::endl;
	std::cout << "------------------" <<std::endl;
	
	
	::iter(a, 10, testNum);
	std::cout << "\ntestNum executed" << std::endl;
	std::cout << "-----------------" <<std::endl;


	time_t b[10];

	::iter(b, 10, initTime);
	std::cout << "\ninitTime executed" << std::endl;
	std::cout << "-----------------" <<std::endl;
	

	::iter(b, 10, printTime);
	std::cout << "\nprintTime executed" << std::endl;
	std::cout << "-----------------" <<std::endl;


}