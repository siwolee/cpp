#ifndef ITER_HPP
 #define ITER_HPP

// Your iter function template must work with any type of array. The third parameter
// can be an instantiated function template.
 namespace {
 	template <typename T>
	void iter(T arr[], int length, void (*f)(T &)){
		for (int i = 0; i < length; i++){
			f(arr[i]);
		}
	}
 }

#endif