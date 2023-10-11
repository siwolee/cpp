/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:28:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 15:55:32 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	this->brain->ideas[0] = "kitty kitty";
	std::cout << "\e[0;33mDefault Constructor called of class Cat\e[0m" << std::endl;
};

Cat::Cat(const Cat & copy)
{
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
	std::cout << "\e[0;33mCopy Constructor called of class Cat\e[0m" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "\e[0;31mDestructor called of class Cat\e[0m" << std::endl;
}

Cat & Cat::operator=(const Cat & assign)
{
	if (this != & assign)
		this->type = assign.type;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << this->type << ": .......Meow Meow" << std::endl;
	std::cout << "pointer of Cat is " << this->brain <<std::endl;
	std::cout << "Idea is " << this->brain->ideas[0] <<std::endl;
};

std::string	Cat::getType() const{
	return (this->type);
};