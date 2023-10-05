/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:17:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/02 18:39:51 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
		Fixed const z;
	public:
		Point();
		~Point();
		Point & operator= (const Point& obj);
		Point operator- (const Point& obj);
		Point(const Point& obj);

		Point(float const _x, float const _y);
		Point(float const _x, float const _y, float const _z);
		float getx();
		float gety();
		float getz();
};
