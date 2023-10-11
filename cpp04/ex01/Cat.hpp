/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:28:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 15:16:50 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal {
	private:
		std::string type;
		Brain *brain;
	public:
		Cat();
		Cat(std::string _type);
		Cat(const Cat & copy);
		~Cat();
		Cat& operator=(const Cat & assign);
		void	makeSound() const;
		std::string	getType() const;
};
