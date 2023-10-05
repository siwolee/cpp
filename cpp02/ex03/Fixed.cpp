/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:22:17 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/03 13:30:02 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	this->value = 0;
};

Fixed::~Fixed(){
};

Fixed& Fixed::operator=(const Fixed& obj)
{
	this->value = obj.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed& obj){
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
	this->setRawBits((num << 8));
}

int		floatToFixed(float const num)
{
	return ((roundf(num * (float)(1 << 8))));
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

bool Fixed::operator > (const Fixed& obj){
	return (this->getRawBits() > obj.getRawBits() ? true : false);
}
bool Fixed::operator < (const Fixed& obj){
	return (this->getRawBits() < obj.getRawBits() ? true : false);
}
bool Fixed::operator <= (const Fixed& obj){
	return (this->getRawBits() <= obj.getRawBits() ? true : false);
}
bool Fixed::operator >= (const Fixed& obj){
	return (this->getRawBits() >= obj.getRawBits() ? true : false);
}
bool Fixed::operator == (const Fixed& obj){
	return (this->getRawBits() == obj.getRawBits() ? true : false);
}
bool Fixed::operator != (const Fixed& obj){
	return (this->getRawBits() != obj.getRawBits() ? true : false);
}

//arithmetic
Fixed & Fixed::operator + (const Fixed& obj){
	Fixed *temp = new Fixed();
	temp->setRawBits(this->getRawBits() + obj.getRawBits());
	return (*temp);
}
Fixed & Fixed::operator - (const Fixed& obj){
	Fixed *temp = new Fixed();
	temp->setRawBits(this->getRawBits() - obj.getRawBits());
	return (*temp);
}
Fixed & Fixed::operator * (const Fixed& obj){
	Fixed *temp = new Fixed();
	temp->setRawBits(floatToFixed(this->tofloat() * obj.tofloat()));
	return (*temp);
}
Fixed & Fixed::operator / (const Fixed& obj){
	Fixed *temp = new Fixed();
	temp->setRawBits(floatToFixed(this->tofloat() / obj.tofloat()));
	return (*temp);
}

Fixed & Fixed::operator-- (){
	this->setRawBits(this->getRawBits() - (1));
	return (*this);
}
// to distinguish between prefix & postfix
// just get (int) as a parameter
// it's just C++ syntax. nothing more
// and return the value before the calculation
Fixed & Fixed::operator-- (int){
	Fixed *temp = new Fixed(*this);
	this->setRawBits(this->getRawBits() - (1));
	return (*temp);
}
Fixed & Fixed::operator++ (){
	this->setRawBits(this->getRawBits() + (1));
	return (*this);
}

Fixed & Fixed::operator++ (int){
	Fixed *temp = new Fixed(*this);
	this->setRawBits(this->getRawBits() + (1));
	return (*temp);
}

Fixed & Fixed::min(Fixed &a, Fixed &b){
	return (a.getRawBits() <= b.getRawBits() ? a : b);
}
Fixed & Fixed::min(const Fixed &a, const Fixed &b){
	return (a.getRawBits() <= b.getRawBits() ? const_cast<Fixed&>(a) : const_cast<Fixed&> (b));
}
Fixed & Fixed::max(Fixed &a, Fixed &b){
	return (a.getRawBits() >= b.getRawBits() ? a : b);
}
Fixed & Fixed::max(const Fixed &a, const Fixed &b){
	return (a.getRawBits() >= b.getRawBits() ? const_cast<Fixed&>(a) : const_cast<Fixed&> (b));
}