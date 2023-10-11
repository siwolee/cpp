/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:28:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/11 19:04:10 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : virtual public Animal {
	private:
	public:
		Cat();
		Cat(std::string _type);
		Cat(const Cat & copy);
		~Cat();
		Cat& operator=(const Cat & assign);
		void	makeSound() const;
		std::string	getType() const;
};
