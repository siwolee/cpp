/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:09 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/04 16:45:35 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){};

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name"){
	this->name = _name;
	std::cout << "DiamondTrap " << this->name << " has born!!!\n";
};

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << this->name << " is died. <RIP>\n";
};

DiamondTrap::DiamondTrap(const DiamondTrap & obj){
		if (this != &obj)
		*this = obj;
};

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & obj){
	if (this != &obj)
	{
		this->name = obj.name;
		this->FragTrap::hit = obj.FragTrap::hit;
		this->ScavTrap::energy = obj.ScavTrap::energy;
		this->FragTrap::damage = obj.FragTrap::damage;
	}
	return (*this);
};

void	DiamondTrap::attack(const std::string& target) {
	FragTrap::attack(target);
};
                                                             
void	DiamondTrap::takeDamage(unsigned int amount){
	std::cout << "DiamondTrap " << this->name << " attacked. Lost " \
	<< amount << " points from damage!\n";
	this->FragTrap::hit -= amount;
};
void	DiamondTrap::beRepaired(unsigned int amount){
	if (this->ScavTrap::energy <= 0 || this->FragTrap::hit <= 0)
	{
		std::cout << "DiamondTrap " << this->name << " has no Energy! Cannot repair\n";
		return;
	}
	std::cout << "DiamondTrap " << this->name << " is repaired\n";
	this->FragTrap::hit += amount;
	this->ScavTrap::energy--;
};

void	DiamondTrap::whoAmI(){
	std::cout << "--------------------------<<\n";
	std::cout << "name   : " << this->name << "\n";
	std::cout << "cp_name: " << this->ClapTrap::name << "\n";
	std::cout << "hit    : " << this->FragTrap::hit<< "\n";
	std::cout << "energy : " << this->ScavTrap::energy<< "\n";
	std::cout << "damage : " << this->FragTrap::damage<< "\n";
	std::cout << "--------------------------<<\n";
};
