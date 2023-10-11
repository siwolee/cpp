/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:14:23 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 20:21:21 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Cure : virtual public AMateria 
{
	private:
		std::string type;
	public:
		Cure();
		Cure(const Cure & copy);
		~Cure();
		Cure & operator=(const Cure & assign);
		virtual std::string const & getType() const; 
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};