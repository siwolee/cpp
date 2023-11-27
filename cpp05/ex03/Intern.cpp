#include "Intern.hpp"


AForm * Intern::makeForm(std::string formName, std::string target){
	try {
		for (int i = 0; i < 4; i++){
			if (fourForms[i] == formName){
				std::cout << "Intern creates " << formName << std::endl;
				return (fourForms[i](target));
			}
		}
	}
}

Intern::Intern(): 	formNames[0]("Shrubbery Creation"), 
					formNames[1]("Robotomy Request"), 
					formNames[2]("Presidential Pardon") {}

Intern::~Intern(): formNames[0]("Shrubbery Creation"), 
					formNames[1]("Robotomy Request"), 
					formNames[2]("Preidential Pardon") {}

Intern & Intern::operator = (const Intern & assign){
	(void)assign;
	return (*this);
}

Intern::Intern (const Intern & copy){
	(void)copy;
}

const char * Intern::FormNotFoundException::what() const throw(){
	return ("Intern: \"I can't find this form... sorry...\"");
}
