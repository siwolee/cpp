/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:46:55 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/11 18:51:37 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		this->material[i] = NULL;
};
MateriaSource::MateriaSource(const MateriaSource & copy){
	*this = copy;
};

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
		if (this->material[i] != NULL)
			delete this->material[i];
};
MateriaSource & MateriaSource::operator=(const MateriaSource & assign){
	if (this != &assign)
		for (int i = 0; i < 4; i++)
			this->material[i] = assign.material[i]->clone();
	return (*this);
};

//stub 매개변수
void MateriaSource::learnMateria(AMateria* mat) {
	for (int i = 0; i < 4; i++)
	{
		if (this->material[i] == NULL){
			this->material[i] = mat;
			return;
		}
	}
};

AMateria* MateriaSource::createMateria(std::string const & type){
	AMateria *clone = NULL; 
	for (int i = 0; i < 4; i++)
	{
		if (this->material[i] == NULL)
			break ;
		if (this->material[i]->getType() == type){
			clone = this->material[i]->clone();
			return (clone);
		}
	}
	return (clone);
};