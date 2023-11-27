#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		std::string	const	name;
		bool				isSigned;
		int					signGrade;
		int					execGrade;
		std::string 		target;
		AForm();
		AForm(std::string _name);
	public:
		virtual 			~AForm();
		std::string			getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		bool				getIsSigned() const;
		void				beSigned(const Bureaucrat & b);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & out, const AForm & self);

#endif