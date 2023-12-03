#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	Bureaucrat	a = Bureaucrat("John", 75);
	Form		f = Form("high form", 1, 0);
	Form		g = Form("mid form");
	Form		h = Form("low form", 50, 151);

	std::cout << a << std::endl;
	a.signForm(&f);
	a.signForm(&g);
	a.signForm(&h);

	std::cout<< f<< g<< h;

}