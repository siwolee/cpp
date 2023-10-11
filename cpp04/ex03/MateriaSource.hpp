/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:46:55 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 21:55:39 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : virtual public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource & copy);
		~MateriaSource();
		MateriaSource & operator=(const MateriaSource & assign);
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

MateriaSource::MateriaSource(){};
MateriaSource::MateriaSource(const MateriaSource & copy){
	*this = &copy;
};

MateriaSource::~MateriaSource(){};
MateriaSource & MateriaSource::operator=(const MateriaSource & assign){
	if (this != &assign)
		{}
	return (*this);
};
virtual void MateriaSource::learnMateria(AMateria*);
virtual AMateria* MateriaSource::createMateria(std::string const & type);