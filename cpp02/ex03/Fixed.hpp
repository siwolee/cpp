/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:21:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/03 13:20:47 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed {
	private:
		int 				value;
		const static int	bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed & operator = (const Fixed& obj);
		Fixed(const Fixed& obj);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		Fixed(int const num);
		Fixed(float const num);
		float	tofloat(void) const;
		int		toInt(void) const;

		//comparison
		bool operator > (const Fixed& obj);
		bool operator < (const Fixed& obj);
		bool operator <= (const Fixed& obj);
		bool operator >= (const Fixed& obj);
		bool operator == (const Fixed& obj);
		bool operator != (const Fixed& obj);

		//arithmetic
		Fixed & operator + (const Fixed& obj);
		Fixed & operator - (const Fixed& obj);
		Fixed & operator * (const Fixed& obj);
		Fixed & operator / (const Fixed& obj);

		Fixed & operator-- ();
		Fixed & operator-- (int);
		Fixed & operator++ ();
		Fixed & operator++ (int);
		
		static Fixed & min(Fixed &a, Fixed &b);
		static Fixed & min(const Fixed &a, const Fixed &b);
		static Fixed & max(Fixed &a, Fixed &b);
		static Fixed & max(const Fixed &a, const Fixed &b);
};

std::ostream & operator << (std::ostream &out, const Fixed &num);
int		floatToFixed(float const num);
