/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:48:00 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/11 18:50:19 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
		AMateria();
	public:
		AMateria(std::string const & type);
		virtual ~AMateria(){};
		std::string const & getType() const; //Returns the materia type
		virtual			AMateria* clone() const = 0;
		virtual void	use(ICharacter& target) = 0;
};
