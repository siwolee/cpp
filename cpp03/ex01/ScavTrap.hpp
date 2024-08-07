/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:28:10 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/09 12:25:38 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	private:
		ScavTrap();
	public:
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap & operator=(const ScavTrap & obj);
		ScavTrap(const ScavTrap & obj);
		void	guardGate();
		void	setName(std::string _name);
		void	attack(const std::string& target);
};
