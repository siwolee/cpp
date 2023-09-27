/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:45:35 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/26 19:45:07 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ){
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N ; i++){
		horde[i].newname(name);
	}
	return (horde);
}