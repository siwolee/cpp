/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:22:17 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/30 15:59:16 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
	// std::cout << "getRawBits member function called\n";
	return (this->value);
}

void Fixed::setRawBits( int const raw ){
	this->value = raw;
}



std::ostream & operator << (std::ostream &out, const Fixed &num){
	out << num.tofloat();
	return (out);
};

Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called\n";
	this->setRawBits(num << 8);
}

Fixed::Fixed(float const num)
{
	int a;
	int b;
	float fnum;
	std::cout << "Float constructor called\n";
	
	a = static_cast<int>(num) << this->bits;
	fnum = num - static_cast<int>(num);
	b = 0;
	for (int i = 0; i < this->bits; i++)
	{
		fnum *= 2.0;
		if (fnum > 1.0)
		{
			fnum -= 1.0;
			b += (1 << (this->bits - i));
		}
	}
	this->setRawBits(a + b);
}
float	Fixed::tofloat(void) const{
	int		a;
	float	b = 0.0;
	int		fnum;
	float	exp = 1;


	a = (this->getRawBits()) >> 8;
	fnum = (this->getRawBits()) & 511;
	for (int i = 0; i < 8; i++)
	{
		exp /= 2.0;
		if (fnum & 256)
		{
			b += exp;
		}
		fnum = fnum << 1;
	}
	return ((float)a + b);
}
int		Fixed::toInt(void) const{
	return ((this->getRawBits()) >> 8);
}