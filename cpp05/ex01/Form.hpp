#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include "./Bureaucrat.hpp"

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

class Bureaucrat;

//const 해석
class Form {
	public:
		Form();
		~Form();
		Form(std::string _name);
		Form(std::string _name, int _signGrade, int _execGrade);
		Form & operator=(const Form & assign);
		Form(const Form & copy);
		std::string			getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		bool				getIsSigned() const;
		void				beSigned(const Bureaucrat & b);
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
		bool				isSigned;
		int					signGrade;
		int					execGrade;
};

std::ostream & operator<<(std::ostream & out, const Form & self);

#endif