/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:09 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/04 18:19:04 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	protected:
		int			hit;
		int			energy; //attck and repair, 1pts
		int			damage;
	public:
		FragTrap();
		FragTrap(std::string _name);
		~FragTrap();
		FragTrap(const FragTrap & obj);
		FragTrap &	operator=(const FragTrap & obj);
		void		highFivesGuys(void);
		
		void		setName(std::string _name);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};
