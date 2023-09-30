/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:21:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/30 13:24:29 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

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

};

std::ostream & operator << (std::ostream &out, const Fixed &num);
