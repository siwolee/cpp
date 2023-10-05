/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:21:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/03 12:25:04 by siwolee          ###   ########.fr       */
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
		Fixed& operator=(const Fixed& obj);
		Fixed(const Fixed& obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
