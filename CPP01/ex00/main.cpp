/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:51:40 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/30 10:51:46 by siwolee          ###   ########.fr       */
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
}