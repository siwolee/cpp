/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:14:23 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 21:32:48 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice : virtual public AMateria 
{
	private:
		std::string type;
	public:
		Ice();
		Ice(const Ice & copy);
		~Ice();
		Ice & operator=(const Ice & assign);
		virtual std::string const & getType() const; 
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};