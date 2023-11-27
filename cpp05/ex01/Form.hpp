#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string	const	name;
		bool				isSigned;
		int					signGrade;
		int					execGrade;
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
};

std::ostream & operator<<(std::ostream & out, const Form & self);

#endif