#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	Bureaucrat	a = Bureaucrat("John");
	Form		f = Form("high form", 1, 1);
	Form		g = Form("low form");
	Form		h = Form("middle form", 50, 50);

	std::cout << a << std::endl;
	a.signForm(&f);
	a.signForm(&g);
	a.signForm(&h);

	std::cout<< f<< g<< h;

}