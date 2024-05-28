#ifndef ITER_HPP
 #define ITER_HPP

// Your iter function template must work with any type of array. The third parameter
// can be an instantiated function template.
template <typename T>
void iter(T* arr, unsigned int const length, void (*f)(const T &)){
	for (unsigned int i = 0; i < length; i++){
		f(arr[i]);
	}
}
template <typename T>
void iter(T* arr, std::size_t const length, void (*f)(T &))
{
	for (unsigned int i = 0; i < length; i++){
		f(arr[i]);
	}
}


#endif