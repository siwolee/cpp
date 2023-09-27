/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:47:29 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/26 19:49:36 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie{
	private:
		std::string	name;
	public:
		void	announce(void);
		void	ramdomChump(std::string name);
		void	newname(std::string name);
		Zombie(std::string name);
		Zombie();
		~Zombie();
};

Zombie*	newZombie(std::string name);
Zombie*	zombieHorde(int N, std::string name);