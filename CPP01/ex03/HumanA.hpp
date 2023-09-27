/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:12:08 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/26 20:53:16 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanA{
	private:
		Weapon& wp;
		std::string name;
	public:
		HumanA(std::string name, Weapon& wp);
		void	attack();
};
