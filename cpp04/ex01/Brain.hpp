/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:24:58 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/09 21:15:44 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain{
	protected:
	public:
		Brain();
		virtual ~Brain();
		Brain(const Brain & copy);
		Brain & operator = (const Brain & assign);
		std::string	ideas[100];
};