/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:17:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/02 18:39:54 by siwolee          ###   ########.fr       */
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
		const_cast<Fixed &>(this->z) = obj.z;
	}
	return (*this);
};
Point::Point(const Point& obj): x(obj.x), y(obj.y), z(obj.z){};

Point::Point(float const _x, float const _y) : x(_x), y(_y), z(0){};

Point::Point(float const _x, float const _y, float const _z) : x(_x), y(_y), z(_z){};

float Point::getx(){
	return (this->x.tofloat());
};
float Point::gety(){
	return (this->y.tofloat());
};
float Point::getz(){
	return (this->z.tofloat());
};

Point Point::operator- (const Point& obj){
	Point	temp = Point(obj);
	return (Point(this->getx() - temp.getx(), this->gety() -  temp.gety()));
};