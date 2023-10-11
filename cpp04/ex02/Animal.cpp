/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:15:09 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 16:45:44 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

IAnimal::IAnimal()
{
};

IAnimal::IAnimal(const IAnimal & copy)
{
	this->type = copy.type;
}

IAnimal::~IAnimal()
{
}

IAnimal & IAnimal::operator=(const IAnimal & assign)
{
	if (this != & assign)
		this->type = assign.type;
	return *this;
}
