/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:12:08 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/26 20:53:28 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack(){
	std::cout << this->name << " attacks with their " \
		<< this->wp.getType() << "\n";
}

HumanA::HumanA(std::string name, Weapon &wp): wp(wp){
	this->name = name;
}


