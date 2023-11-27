#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>


class Bureaucrat {
	private:
		std::string	const	name;
		int					grade;
	public:
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
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & out, const Bureaucrat & self);

#endif