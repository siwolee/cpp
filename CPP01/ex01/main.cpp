/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:11:39 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/30 10:52:08 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	leaks()
{
	system("leaks zombie");
}

int main()
{
	// atexit(leaks);
	Zombie* horde;

	horde = zombieHorde(4, "newbie");

	for (int i = 0; i < 4; i++){
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}