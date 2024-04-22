#ifndef TEMPLATE_HPP
 #define TEMPLATE_HPP

namespace {
	template <typename T>
	void swap(T & a, T & b){
		T temp = a;
		a = b;
		b = temp;
	}

	template <typename T>
	T min(T const & a, T const & b){
		if (a < b)
			return a;
		else
			return b; 
	}

	template <typename T>
	T max(T const & a, T const & b){
		if (a > b)
			return a;
		else
			return b; 
	}	
}

#endif