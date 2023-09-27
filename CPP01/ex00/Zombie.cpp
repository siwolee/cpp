/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:45:35 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/26 19:51:00 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
};

Zombie::~Zombie(){
	std::cout << this->name << ": is deleted\n";
};

Zombie::Zombie(){};

Zombie::Zombie(std::string name){
	this->name = name;
}