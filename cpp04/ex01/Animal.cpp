/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:15:09 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/09 21:16:25 by siwolee          ###   ########.fr       */
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

std::string Animal::getType() const{
	return (this->type);
};

void	Animal::makeSound() const
{
	std::cout << "(No Sound)\n" ;
};