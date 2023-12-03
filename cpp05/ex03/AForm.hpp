#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

class Bureaucrat;

class AForm {
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
	protected:
		std::string	const	name;
		bool				isSigned;
		int					signGrade;
		int					execGrade;
		std::string 		target;
		AForm();
		AForm(std::string _name);
		AForm(std::string _name, int _signGrade, int _execGrade);
};

std::ostream & operator<<(std::ostream & out, const AForm & self);

#endif