/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:14:23 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/11 18:49:53 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice : virtual public AMateria 
{
	private:
	public:
		Ice();
		Ice(const Ice & copy);
		~Ice();
		Ice & operator=(const Ice & assign);
		virtual std::string const & getType() const; 
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};