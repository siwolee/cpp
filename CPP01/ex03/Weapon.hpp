/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:11:26 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/26 20:39:00 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		std::string&	getType();
		void			setType(std::string type);
};