/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:57:37 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 21:25:57 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): type("cure"){

};

Cure::Cure(const Cure & copy){
	*this = copy;
};

Cure::~Cure(){
};

Cure & Cure::operator=(const Cure & assign){
	if (this != &assign)
		this->type = assign.type;
	return (*this);
};

std::string const & Cure::getType() const
{
	return (this->type);
}; 

AMateria* Cure::clone() const{
	return (new Cure());
};

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" <<std::endl;
};