/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat copy.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:28:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 16:01:14 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "\e[0;33mDefault Constructor called of class WrongCat\e[0m" << std::endl;
};

WrongCat::WrongCat(const WrongCat & copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of class WrongCat\e[0m" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of class WrongCat\e[0m" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat & assign)
{
	if (this != & assign)
		this->type = assign.type;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << this->type << ": .......Meow Meow" << std::endl;
};

std::string	WrongCat::getType() const{
	return (this->type);
};