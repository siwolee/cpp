#ifndef SCALACONVERTER_HPP
# define SCALACONVERTER_HPP
#include <iostream>

//static class Objects

class ScalaConverter {
	public :
		ScalaConverter();
		~ScalaConverter();
		static void convert(std::string str);
		
	private:
		ScalaConverter(ScalaConverter & copy);
		ScalaConverter & operator=(ScalaConverter & assign);
};

#endif
