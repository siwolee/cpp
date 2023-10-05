/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:43:11 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/02 20:21:08 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): hit(10), energy(10), damage(0){
	this->name = "default";
	std::cout << "ClapTrap " << this->name << " has born!!!\n";
};

ClapTrap::ClapTrap(std::string _name): name(_name), hit(10), energy(10), damage(0){
	std::cout << "ClapTrap " << this->name << " has born!!!\n";
};

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->name << " is died. <RIP>\n";
};

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->hit = obj.hit;
		this->energy = obj.energy;
		this->damage = obj.damage;
	}
	return (*this);
};
ClapTrap::ClapTrap(const ClapTrap& obj)
{
	if (this != &obj)
		*this = obj;
};
void	ClapTrap::attack(const std::string& target){
	if (this->energy <= 0 || this->hit <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no Energy! Cannot attack\n";
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacks " \
		<< target << ", causing " << this->damage << " points of damage!\n";
	this->energy--;
};
void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << this->name << " attacked. Lost " \
	<< amount << " points from damage!\n";
	this->hit -= amount;
};
void	ClapTrap::beRepaired(unsigned int amount){
	if (this->energy <= 0 || this->hit <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no Energy! Cannot repair\n";
		return;
	}
	std::cout << "ClapTrap " << this->name << " is repaired\n";
	this->hit += amount;
	this->energy--;
};
