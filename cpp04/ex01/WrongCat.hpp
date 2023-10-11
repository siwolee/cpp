/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:28:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 13:31:59 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal {
	private:
	public:
		WrongCat();
		WrongCat(std::string _type);
		WrongCat(const WrongCat & copy);
		~WrongCat();
		WrongCat& operator=(const WrongCat & assign);
		void	makeSound() const;
		std::string	getType() const;
};
