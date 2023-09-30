/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:22:32 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/30 19:30:12 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float dot(Point a, Point b)
{
	float x = (a.getX() * b.getX());
	float y = (b.getY() * a.getY());
	return (x + y);
}

//check if c and p is on the same side of line (ab)
bool isSameSide ( Point const a, Point const b, Point const c, Point const p)
{
	int res = 0;

	res += (dot(a, p)? 1 : 0);
	res += (dot(b, p)? 1 : 0);
	res += (dot(c, p)? 1 : 0);
	if (res == 3)
		return true;
	return false;
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	return (isSameSide(a, b, c, point));
}