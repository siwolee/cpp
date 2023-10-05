/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:09 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/04 16:42:10 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap{
	private:
		DiamondTrap();
		std::string name;

	public:
		DiamondTrap(std::string _name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap & obj);
		DiamondTrap &	operator=(const DiamondTrap & obj);
		void		highFivesGuys(void);

		void		setName(std::string _name);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		void		whoAmI();
};
