/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:22:17 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/03 13:14:20 by siwolee          ###   ########.fr       */
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
	this->setRawBits(num << (1 << this->bits));
}

Fixed::Fixed(float const num)
{
	this->setRawBits(roundf(num * (1 << this->bits)));
}

float	Fixed::tofloat(void) const{
	return (this->getRawBits() / (float)(1 << this->bits));
}

int		Fixed::toInt(void) const{
	return ((roundf(this->getRawBits() / (float)(1 << this->bits))));
}