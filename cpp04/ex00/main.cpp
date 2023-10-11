/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:26:16 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/11 19:18:26 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void leaks()
{
	system("leaks ex");
}

int main()
{
	atexit(leaks);
	{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal *wcat = new WrongCat();
	std::cout << wcat->getType() << " " << std::endl;
	wcat->makeSound();

	delete i;
	delete j;
	delete meta;
	delete wcat;
	}
	return 0;
};