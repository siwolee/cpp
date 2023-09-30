/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:22:17 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/30 11:22:33 by siwolee          ###   ########.fr       */
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
	std::cout << "getRawBits member function called\n";
	return (this->value);
}

void Fixed::setRawBits( int const raw ){
	this->value = raw;
}
