/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:15:09 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/05 19:55:32 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "(empty)";
	std::cout << "\e[0;33mDefault Constructor called of class Animal\e[0m" << std::endl;
};

Animal::Animal(const Animal & copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of class Animal\e[0m" << std::endl;
}

Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of class Animal\e[0m" << std::endl;
}

Animal & Animal::operator=(const Animal & assign)
{
	if (this != & assign)
		this->type = assign.type;
	return *this;
}

std::string Animal::getType(){
	return (this->type);
};

void	Animal::makeSound()
{
};