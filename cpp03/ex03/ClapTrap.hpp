/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:43:11 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/04 18:17:50 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ClapTrap
{
	protected:
		std::string	name;
		int			hit;
		int			energy; //attck and repair, 1pts
		int			damage;
		ClapTrap();
	public:
		ClapTrap(std::string _name);
		~ClapTrap();
		ClapTrap & operator=(const ClapTrap& obj);
		ClapTrap(const ClapTrap& obj); 
		void		setName(std::string _name);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};
