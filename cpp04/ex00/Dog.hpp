/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:28:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/11 19:03:53 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : virtual public Animal {
	private:
	public:
		Dog();
		Dog(std::string _type);
		Dog(const Dog & copy);
		~Dog();
		Dog& operator=(const Dog & assign);
		void	makeSound() const;
		std::string	getType() const;
};
