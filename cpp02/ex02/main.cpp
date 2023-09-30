/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:42:05 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/30 18:12:44 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed temp(-1);

	a = Fixed( 1234.4321f );

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	std::cout << "\n=comparison=================\n";
	std::cout << a << " < " << b << " is " << (a < b) << "\n";
	std::cout << a << " > " << b << " is " << (a > b) << "\n";
	std::cout << a << " <= " << b << " is " << (a <= b) << "\n";
	std::cout << a << " < " << c << " is " << (a < c) << "\n";
	std::cout << a << " < " << temp << " is " << (a < temp) << "\n";
	std::cout << b << " >= " << d << " is " << (const_cast<Fixed &>(b) >= d) << "\n";

	std::cout << "\n=arithmetic=================\n";
	std::cout << a << " + " << b << " is " << (a + b) << "\n";
	std::cout << a << " - " << b << " is " << (a - b) << "\n";
	std::cout << a << " * " << b << " is " << (a * b) << "\n";
	std::cout << a << " / " << b << " is " << (a / b) << "\n";
	std::cout << a << " * " << temp << " is " << (a * temp) << "\n";

	std::cout << "\n=prefix postfix=============\n";
	std::cout << a << " ++ is " << ++a << "\n";
	std::cout << " ++" << a  << " is "<< a++ << "\n";

	std::cout << "\n=example====================\n";
	Fixed aa = Fixed();
	Fixed bb( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << aa << std::endl;
	std::cout << ++aa << std::endl;
	std::cout << aa << std::endl;
	std::cout << aa++ << std::endl;
	std::cout << aa << std::endl;
	std::cout << bb << std::endl;
	std::cout << Fixed::max( aa, bb ) << std::endl;

	return 0;
}