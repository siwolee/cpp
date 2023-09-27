/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:12:08 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/26 20:56:24 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanB{
	private:
		Weapon*	wp;
		std::string name;
	public:
		HumanB(std::string name);
		void	attack();
		void	setWeapon(Weapon& wp);
};

