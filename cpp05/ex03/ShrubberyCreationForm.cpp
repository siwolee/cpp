#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137) {
	target = "garden";
};

ShrubberyCreationForm::~ShrubberyCreationForm(){};

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): AForm("ShrubberyCreationForm", 145, 137) {
	target = _target;
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
	std::cout << BOLDYELLOW << std::setw(20) << std::left << "ShrubberyCreation" << RESET << "|";
	std::cout << BOLDYELLOW  << std::setw(10) << std::left << executor.getName() << RESET << "|";
	std::cout << BOLDYELLOW  << std::setw(10) << std::left << target << RESET << "|";
	try {
		if (executor.getGrade() > execGrade)
			throw AForm::GradeTooLowException();
		std::cout << BOLDGREEN << std::setw(12) << std::left << "sucess✅" << RESET << "|";
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
		std::cout << target << std::setw(50) << std::left << " created :"+ filename << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cout << BOLDRED << std::setw(13) << std::left << "fail🚫" << RESET << "|";
		std::cout << std::setw(50) << std::left << std::setfill('.') << RESET << std::endl << std::setfill(' ');
	}
}

