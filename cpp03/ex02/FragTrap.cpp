/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:09 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/04 16:45:35 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){};

FragTrap::FragTrap(std::string _name){
	this->name = _name;
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap " << this->name << " has born!!!\n";
};

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << this->name << " is died. <RIP>\n";
};

FragTrap::FragTrap(const FragTrap & obj){
		if (this != &obj)
		*this = obj;
};

FragTrap & FragTrap::operator=(const FragTrap & obj){
	if (this != &obj)
	{
		this->name = obj.name;
		this->hit = obj.hit;
		this->energy = obj.energy;
		this->damage = obj.damage;
	}
	return (*this);
};

void	FragTrap::highFivesGuys(void)
{
	std::cout <<"\033[1m\033[33m"<< " OK, High_Five GUYs!!                                         \n";
	std::cout << "                                                              \n";
	std::cout << "                    jJ|                                       \n";
	std::cout << "                   Jp vappJ                                   \n";
	std::cout << "                  >pa; O| JaOa_           jO_                 \n";
	std::cout << "                 |a }p ;O; p>_a       Oaaa| a|                \n";
	std::cout << "                  a} Ov vJ }a va}a}a}Jv vJ }aO                \n";
	std::cout << "                  ^a  O_ J| JJ aav aaO _O  a> a               \n";
	std::cout << "                   vO _a} ^     a| aa; O} Oj vp               \n";
	std::cout << "               aaOaaav          a  a| Jv vO ;a                \n";
	std::cout << "                ap  Jaaa>      ja >p  J^^p^ a_                \n";
	std::cout << "                  a>     pJ    a_          OaaaaaO            \n";
	std::cout << "                   aJ     v   Jv          >a;  aa             \n";
	std::cout << "                    va^       aj          JJ }a               \n";
	std::cout << "                      paO^   Oaa            OO                \n";
	std::cout << "                      Ov      aOa ||   |^ >a|                 \n";
	std::cout << "                       pv   _a_  a>      OO                   \n";
	std::cout << "                         _Jj     }a      }a^                  \n";
	std::cout << "                                  JO^JapOOav                  \n";
	std::cout << "                                   aapppO}                    \033[0m\n"  << std::endl;
};

void	FragTrap::attack(const std::string& target){
	if (this->energy <= 0 || this->hit <= 0)
	{
		std::cout << "FragTrap " << this->name << " has no Energy! Cannot attack\n";
		return;
	}
	std::cout << "FragTrap " << this->name << " attacks " \
		<< target << ", causing " << this->damage << " points of damage!\n";
	this->energy--;
};
                                                             
void	FragTrap::takeDamage(unsigned int amount){
	std::cout << "FragTrap " << this->name << " attacked. Lost " \
	<< amount << " points from damage!\n";
	this->hit -= amount;
};
void	FragTrap::beRepaired(unsigned int amount){
	if (this->energy <= 0 || this->hit <= 0)
	{
		std::cout << "FragTrap " << this->name << " has no Energy! Cannot repair\n";
		return;
	}
	std::cout << "FragTrap " << this->name << " is repaired\n";
	this->hit += amount;
	this->energy--;
};