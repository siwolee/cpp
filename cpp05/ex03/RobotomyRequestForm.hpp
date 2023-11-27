#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "./Bureaucrat.hpp"


class  RobotomyRequestForm : public AForm {
	private:
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string _target);

		RobotomyRequestForm & operator=(const RobotomyRequestForm & assign);
		RobotomyRequestForm(const RobotomyRequestForm & copy);
		virtual void		execute(Bureaucrat const & executor) const;
};


#endif