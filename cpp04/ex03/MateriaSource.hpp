/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:46:55 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/11 18:49:24 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : virtual public IMateriaSource {
	// private:
	// 	AMateria *material[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource & copy);
		~MateriaSource();
		MateriaSource & operator=(const MateriaSource & assign);
		virtual void learnMateria(AMateria* mat);
		virtual AMateria* createMateria(std::string const & type);
};
