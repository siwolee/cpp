/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:15:09 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/09 21:16:25 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of class Brain\e[0m" << std::endl;
};

Brain::Brain(const Brain & copy)
{
	for (int i = 0; i < 100 ; i++)
		this->ideas[i] = copy.ideas[i];
	std::cout << "\e[0;33mCopy Constructor called of class Brain\e[0m" << std::endl;
}

Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of class Brain\e[0m" << std::endl;
}

Brain & Brain::operator=(const Brain & assign)
{
	if (this != & assign)
		for (int i = 0; i < 100 ; i++)
			this->ideas[i] = assign.ideas[i];
	return *this;
}
