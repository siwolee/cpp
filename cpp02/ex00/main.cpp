/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:42:05 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/28 18:00:55 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {
	private:
		int 				value;
		const static int	bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed& operator=(const Fixed& obj);
		Fixed(const Fixed& obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

Fixed::Fixed(){
	std::cout << "Default constructor called\n";
	this->value = 0;
};

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
};

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called\n";
	this->value = obj.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed& obj){
	std::cout << "Copy constructor called\n";
	*this = obj;
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}

void Fixed::setRawBits( int const raw ){
	this->value = raw;
}

int main()
{
	Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}