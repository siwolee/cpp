/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:42:32 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/04 18:20:55 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// multiple inheritance
int main()
{
	DiamondTrap trap = DiamondTrap("JNR");
	std::cout << std::endl;
	trap.whoAmI();
	std::cout << std::endl;
	trap.attack("boss");
	trap.takeDamage(3);
	trap.attack("superior");
	trap.beRepaired(1);
	trap.attack("boss");
	std::cout << std::endl;
};