/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:26:16 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 16:46:05 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	IAnimal *meta[4];
	meta[0] = new Dog();
	meta[1] = new Dog(); 
	*meta[1] = *meta[0];//copy of Dog;
	
	meta[0]->makeSound();
	meta[1]->makeSound();

	meta[2] = new Cat();
	meta[3] = new Cat();
	*meta[3] = *meta[2];

	meta[2]->makeSound();
	meta[3]->makeSound();

	for (int i = 0; i < 4 ; i++)
		delete meta[i];

	Cat kitty = Cat();
	Cat kittycopy = Cat(kitty);
	
	kitty.makeSound();
	kittycopy.makeSound();
	return 0;
};