/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:42:05 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/30 19:27:58 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	
	std::cout << " False : " << bsp (Point(1,2), Point(0,0), Point(2,0), Point(2,2)) <<"\n";
	std::cout << "  True : " << bsp (Point(1,2), Point(0,0), Point(2,0), Point(1,1)) <<"\n";

	return (0);
}