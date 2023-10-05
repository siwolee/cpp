/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:42:05 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/02 18:38:44 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	
	std::cout << " False : " << bsp (Point(1,2), Point(0,0), Point(2,0), Point(2,2)) <<"\n";
	std::cout << "  True : " << bsp (Point(1,2), Point(0,0), Point(2,0), Point(1,1)) <<"\n";
	std::cout << "  True : " << bsp (Point(100,20), Point(0,-1), Point(50,50), Point(50,49)) <<"\n";
	std::cout << " False : " << bsp (Point(100,20), Point(0,-1), Point(50,50), Point(100,49)) <<"\n";

	return (0);
}