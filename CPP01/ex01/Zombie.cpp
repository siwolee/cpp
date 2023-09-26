/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:45:35 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/26 19:50:38 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::Zombie(std::string name){
	this->name = name;
}

Zombie::~Zombie(){
	std::cout << this->name << ": is deleted\n";
}

void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie*	newZombie(std::string name){
	Zombie *ptr = new Zombie(name);

	return (ptr);
}

void	Zombie::newname(std::string name){
	this->name = name;
};

void	ramdomChump(std::string name){
	Zombie newbie = Zombie(name);
	newbie.announce();
}
