#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public: 

	AForm * makeForm(std::string formName, std::string target);
	Intern();
	~Intern();
	Intern & operator = (const Intern & assign);
	Intern (const Intern & copy);

	private:
	std::map<std::string, void *(*ptr)(std::string target)> forms;
	class FormNotFoundException : public std::exception {
		public:
			virtual const char * what() const throw();
		};
};

#endif