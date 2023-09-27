#include <iostream>
#include <iomanip>

int	main()
{
	std::string	hi = "HI THIS IS BRAIN";
	std::string* stringPTR = &hi;
	std::string& stringREF = hi;
	
	std::cout << std::setw(30) << "address of the variable is :";
	std::cout << &hi << "\n";
	std::cout << std::setw(30) << "address held by pointer is :";
	std::cout << stringPTR << "\n";
	std::cout << std::setw(30) << "address held by reference is :";
	std::cout << &stringREF << "\n\n";

	std::cout << std::setw(30) << "value of the variable is :";
	std::cout << hi << "\n";
	std::cout << std::setw(30) << "value of the pointer is :";
	std::cout << *stringPTR << "\n";
	std::cout << std::setw(30) << "value of the reference is :";
	std::cout << stringREF << "\n";

	return (0);
}