/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:28:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 13:35:19 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "\e[0;33mDefault Constructor called of class Dog\e[0m" << std::endl;
};

Dog::Dog(const Dog & copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of class Dog\e[0m" << std::endl;
}

Dog::~Dog()
{
	std::cout << "\e[0;31mDestructor called of class Dog\e[0m" << std::endl;
}

Dog & Dog::operator=(const Dog & assign)
{
	if (this != & assign)
		this->type = assign.type;
	return *this;
}

void	Dog::makeSound() const{
	std::cout << this->type << ": .......BowWow" << std::endl;
};

std::string	Dog::getType() const{
	return (this->type);
};