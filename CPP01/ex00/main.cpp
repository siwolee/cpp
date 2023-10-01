/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:51:40 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/01 19:00:09 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	a = Zombie("oldie");
	Zombie* ptr = NULL;

	a.announce();
	ptr = newZombie("newbie");
	(*ptr).announce();
	delete ptr;
}