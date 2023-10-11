/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:04:12 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 21:24:17 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"

class Character : virtual public ICharacter
{
	private:
		AMateria 		*inventory[4];
		std::string		name;
	public:
		Character();
		Character(const Character & copy);
		Character(std::string _name);
		~Character();
		Character & operator=(const Character & assign);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};