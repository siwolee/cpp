/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:57:37 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/11 18:50:33 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure"){

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