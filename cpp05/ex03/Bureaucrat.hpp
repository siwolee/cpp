#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	public:
		void 				signForm(AForm *form);
		std::string			getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string _name);
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat & operator=(const Bureaucrat & assign);
		Bureaucrat(const Bureaucrat & copy);
		void	executeForm(AForm const & form);
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
	private:
		std::string	const	name;
		int					grade;
};

std::ostream & operator<<(std::ostream & out, const Bureaucrat & self);

#endif