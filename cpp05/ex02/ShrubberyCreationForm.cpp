#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm") {
	signGrade = 145;
	execGrade = 137;
	target = "garden";
};

ShrubberyCreationForm::~ShrubberyCreationForm(){};

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): AForm("ShrubberyCreationForm"){
	target = _target;
	signGrade = 145;
	execGrade = 137;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & assign){
	if (this == &assign)
		return (*this)	;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy){
	*this = copy;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > execGrade)
		throw AForm::GradeTooLowException();

	std::ofstream file;
	std::string filename = target + "_shrubbery";
	file.open(filename);
	if (!file.is_open())
		return ;
	file <<"*        * /\\         *"<<std::endl;
	file <<"      *   /i\\\\    *  *"<<std::endl;
	file <<"    *     o/\\\\  *      *"<<std::endl;
	file <<" *       ///\\i\\    *"<<std::endl;
	file <<"     *   /*/o\\\\  *    *"<<std::endl;
	file <<"   *    /i//\\*\\      *"<<std::endl;
	file <<"        /o/*\\\\i\\   *"<<std::endl;
	file <<"  *    //i//o\\\\\\\\     *"<<std::endl;
	file <<"    * /*////\\\\i\\*"<<std::endl;
	file <<" *    //o//i\\*\\\\   *"<<std::endl;
	file <<"   * /i///*/\\\\\\\\\\o\\   *"<<std::endl;
	file <<"  *    *   ||    *     "<<std::endl;           
	file.close();

	std::cout << "ShrubberyCreationForm has been executed by " << executor.getName() << std::endl;
}

