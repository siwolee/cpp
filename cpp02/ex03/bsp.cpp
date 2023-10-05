/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:22:32 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/02 18:30:12 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float dot(Point a, Point b)
{
	float x = (a.getx() * b.getx());
	float y = (b.gety() * a.gety());
	float z = (b.getz() * a.getz());
	return (x + y + z);
}

Point cross(Point a, Point b)
{
	float x = a.gety() * b.getz() - a.getz() * b.gety();
	float y = a.getz() * b.getx() - a.getx() * b.getz();
	float z = a.getx() * b.gety() - a.gety() * b.getx();
	return (Point(x, y, z));
}
//check if c and p is on the same side of line (ab)
//z value is 0
bool isSameSide ( Point a, Point b, Point c, Point p)
{
	
	Point res1 = cross(b-a, c-a);
	Point res2 = cross(b-a, p-a);
	if (dot (res1, res2) >= 0)
	{
		return (true);
	}
	return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	return (isSameSide(a, b, c, point) & isSameSide(b, c, a, point) & isSameSide(c, a, b, point));
}
