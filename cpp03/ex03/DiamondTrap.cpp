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
	this->hit = this->FragTrap::hit;
	this->energy = this->ScavTrap::energy;
	this->damage = this->FragTrap::damage;
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
		this->hit = obj.hit;
		this->energy = obj.energy;
		this->damage = obj.damage;
	}
	return (*this);
};

void	DiamondTrap::attack(const std::string& target){
	FragTrap::attack(target);
};
                                                             
void	DiamondTrap::takeDamage(unsigned int amount){
	std::cout << "DiamondTrap " << this->name << " attacked. Lost " \
	<< amount << " points from damage!\n";
	this->hit -= amount;
};
void	DiamondTrap::beRepaired(unsigned int amount){
	if (this->energy <= 0 || this->hit <= 0)
	{
		std::cout << "DiamondTrap " << this->name << " has no Energy! Cannot repair\n";
		return;
	}
	std::cout << "DiamondTrap " << this->name << " is repaired\n";
	this->hit += amount;
	this->energy--;
};

void	DiamondTrap::whoAmI(){
	std::cout << "--------------------------<<\n";
	std::cout << "name   : " << this->name << "\n";
	std::cout << "cp_name: " << this->ClapTrap::name << "\n";
	std::cout << "hit    : " << this->hit<< "\n";
	std::cout << "energy : " << this->energy<< "\n";
	std::cout << "damage : " << this->damage<< "\n";
	std::cout << "--------------------------<<\n";
};
