/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:12:08 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/26 20:56:41 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack(){
	std::cout << this->name << " attacks with their " \
		<< this->wp->getType() << "\n";
}

HumanB::HumanB(std::string name){
	this->name = name;
}

void	HumanB::setWeapon(Weapon& wp){
	this->wp = &wp;
}

