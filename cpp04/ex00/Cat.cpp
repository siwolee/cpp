/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:28:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/05 19:47:06 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "\e[0;33mDefault Constructor called of class Cat\e[0m" << std::endl;
};

Cat::Cat(const Cat & copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of class Cat\e[0m" << std::endl;
}

Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of class Cat\e[0m" << std::endl;
}

Cat & Cat::operator=(const Cat & assign)
{
	if (this != & assign)
		this->type = assign.type;
	return *this;
}

void	Cat::makeSound(){
	std::cout << this->type << ": .......BowWow\n" << std::endl;
};

std::string	Cat::getType(){
	return (this->type);
};