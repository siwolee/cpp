/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:23:12 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/11 15:02:54 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"


Character::Character(): name(""){
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
};

Character::Character(std::string _name): name(_name){
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
};

Character::Character(const Character & copy){
	*this = copy;
};

Character::~Character(){
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
};

Character & Character::operator=(const Character & assign){
	if (this != &assign)
		for (int i = 0; i < 4; i++){
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			this->inventory[i] = assign.inventory[i]->clone();
		}
	return (*this);
};

std::string const & Character::getName() const{
	return (this->name);
};
void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break ;
		}
}
void Character::unequip(int idx){
	this->inventory[idx] = NULL;
};

void Character::use(int idx, ICharacter& target){
	if (this->inventory[idx] == NULL)
		return ;
	this->inventory[idx]->use(target);
};