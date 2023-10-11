/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:47:29 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/09 12:16:36 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){};

ScavTrap::ScavTrap(std::string _name) {
	this->name = _name;
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap " << this->name << " has born!!!\n";
};

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << this->name << " is died. <RIP>\n";
};

ScavTrap & ScavTrap::operator=(const ScavTrap & obj){
	if (this != &obj)
	{
		this->name = obj.name;
		this->hit = obj.hit;
		this->energy = obj.energy;
		this->damage = obj.damage;
	}
	return (*this);
};

ScavTrap::ScavTrap(const ScavTrap & obj){
	if (this != &obj)
		*this = obj;
};

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->name << " is now on Gatekeeper mode\n";
};

void	ScavTrap::attack(const std::string& target){
	if (this->energy <= 0 || this->hit <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no Energy! Cannot attack\n";
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacks " \
		<< target << ", causing " << this->damage << " points of damage!\n";
	this->energy--;
};

