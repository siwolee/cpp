/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:57:37 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 21:25:57 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){

};

Ice::Ice(const Ice & copy){
	*this = copy;
};

Ice::~Ice(){
};

Ice & Ice::operator=(const Ice & assign){
	if (this != &assign)
		this->type = assign.type;
	return (*this);
};

std::string const & Ice::getType() const
{
	return (this->type);
}; 

AMateria* Ice::clone() const{
	return (new Ice());
};

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
};