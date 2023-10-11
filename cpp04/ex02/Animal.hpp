/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:24:58 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 16:44:50 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class IAnimal
{
	protected:
		std::string	type;
	public:
		IAnimal();
		IAnimal(const IAnimal & copy);
		virtual ~IAnimal();
		virtual IAnimal & operator = (const IAnimal & assign);
		virtual std::string	getType() const = 0;
		virtual void		makeSound() const = 0;
};