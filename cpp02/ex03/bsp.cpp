/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:22:32 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/01 21:00:49 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// float dot(Point a, float ax, Point b, float bx)
// {
// 	float x = (a.getX() * b.getX());
// 	float y = (b.getY() * a.getY());
// 	return (x + y);
// }

float	cross_min(Point a, Point b)
{
	std::cout << (a.getX() * b.getY() - a.getY() * b.getX())<< std::endl;
	return (a.getX() * b.getY() - a.getY() * b.getX());
}

//check if c and p is on the same side of line (ab)
//z value is 0
bool isSameSide ( Point a, Point b, Point p)
{
	if (cross_min(a, b) * cross_min(a, p) > 0)
	{
		return (true);
	}
	return (false);
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	return (isSameSide(a, b, point) & isSameSide(b, c, point) & isSameSide(c, a, point));
}
