/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:42:32 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/02 20:57:15 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap a = ScavTrap("junior");
	a.attack("boss");
	a.takeDamage(3);
	a.attack("superior");
	a.beRepaired(1);
	a.attack("boss");
	a.guardGate();
};