/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:22:17 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/30 18:09:28 by siwolee          ###   ########.fr       */
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
	int a;
	int b;
	float fnum;

	a = static_cast<int>(num) << 8;
	fnum = num - static_cast<int>(num);
	b = 0;
	for (int i = 0; i < 8; i++)
	{
		fnum *= 2.0;
		if (fnum > 1.0)
		{
			fnum -= 1.0;
			b += (1 << (8 - i - 1));
		
		}
	}
	return ((a + b));
}

Fixed::Fixed(float const num)
{
	this->setRawBits(floatToFixed(num));
}

float	Fixed::tofloat(void) const{
	int		a;
	float	b = 0.0;
	int		fnum;
	float	exp = 1;

	a = (this->getRawBits()) >> 8;
	fnum = (this->getRawBits() ) - (a<<8);
	for (int i = 0; i < 8; i++)
	{
		exp /= 2.0;
		if (fnum & 128)
		{
			b += exp;
		}
		fnum = fnum << 1;
	}
	return (((float)a + b));
}
int		Fixed::toInt(void) const{
	return ((this->getRawBits()) >> 8);
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
	temp->setRawBits(floatToFixed(this->tofloat() + obj.tofloat()));
	return (*temp);
}
Fixed & Fixed::operator - (const Fixed& obj){
	Fixed *temp = new Fixed();
	temp->setRawBits(floatToFixed(this->tofloat() - obj.tofloat()));
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