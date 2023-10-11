/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:15:09 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/09 21:16:25 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "(empty)";
	std::cout << "\e[0;33mDefault Constructor called of class WrongAnimal\e[0m" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal & copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of class WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of class WrongAnimal\e[0m" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & assign)
{
	if (this != & assign)
		this->type = assign.type;
	return *this;
}

std::string WrongAnimal::getType() const{
	return (this->type);
};

void	WrongAnimal::makeSound() const
{
	std::cout << "(No Sound)\n" ;
};