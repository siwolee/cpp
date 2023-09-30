/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:17:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/30 19:28:45 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(){};
Point::~Point(){};
Point & Point::operator= (const Point& obj){
	if (this != &obj)
	{
		const_cast<Fixed &>(this->x) = obj.x;
		const_cast<Fixed &>(this->y) = obj.y;
	}
	return (*this);
};
Point::Point(const Point& obj): x(obj.x), y(obj.y){};

Point::Point(float const _x, float const _y) : x(_x), y(_y){};

float Point::getX(){
	return (this->x.tofloat());
};
float Point::getY(){
	return (this->y.tofloat());
};