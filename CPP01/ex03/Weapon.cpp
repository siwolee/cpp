/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:11:28 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/26 20:57:06 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){};

Weapon::Weapon(std::string type){
	this->type = type;
};

std::string&	Weapon::getType(){
	return (this->type);
};

void	Weapon::setType(std::string type){
	this->type = type;
	return ;
};