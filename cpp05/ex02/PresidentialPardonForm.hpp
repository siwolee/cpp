#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "./Bureaucrat.hpp"


class  PresidentialPardonForm : public AForm {
	private:
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string _target);

		PresidentialPardonForm & operator=(const PresidentialPardonForm & assign);
		PresidentialPardonForm(const PresidentialPardonForm & copy);
		virtual void		execute(Bureaucrat const & executor) const;
};


#endif