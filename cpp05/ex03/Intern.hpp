#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public: 

	AForm * makeForm(std::string _formName, std::string target);
	Intern();
	~Intern();
	Intern & operator = (const Intern & assign);
	Intern (const Intern & copy);

	private:
	class FormNotFoundException : public std::exception {
		public:
			virtual const char * what() const throw();
		};
};

#endif