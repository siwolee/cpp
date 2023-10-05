/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:24:58 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/05 19:54:54 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Animal{
	protected:
		std::string	type;
	public:
		Animal();
		~Animal();
		Animal(const Animal & copy);
		Animal & operator = (const Animal & assign);
		std::string	getType();
		void		makeSound();
};