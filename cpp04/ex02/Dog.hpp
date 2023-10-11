/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:28:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 16:45:31 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public IAnimal {
	private:
		std::string type;
		Brain * brain;
	public:
		Dog();
		Dog(std::string _type);
		Dog(const Dog & copy);
		~Dog();
		Dog& operator=(const Dog & assign);
		void	makeSound() const;
		std::string	getType() const;
};
