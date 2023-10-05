/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:42:32 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/04 18:14:00 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap a = FragTrap("junior");
	a.attack("boss");
	a.takeDamage(3);
	a.attack("superior");
	a.beRepaired(1);
	a.attack("boss");
	a.highFivesGuys();
};