#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "./Bureaucrat.hpp"


class  ShrubberyCreationForm : public AForm {
	private:
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _target);

		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & assign);
		ShrubberyCreationForm(const ShrubberyCreationForm & copy);
		virtual void		execute(Bureaucrat const & executor) const;
};


#endif