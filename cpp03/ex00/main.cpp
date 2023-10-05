/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:42:32 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/02 20:21:29 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a = ClapTrap("junior");
	
	a.attack("boss");
	a.takeDamage(3);
	a.attack("superior");
	a.beRepaired(1);
	a.attack("boss");
	a.attack("boss");
	a.attack("boss");
	a.attack("boss");
	a.attack("boss");
	a.attack("boss");
	a.attack("boss");
	a.attack("boss");
};