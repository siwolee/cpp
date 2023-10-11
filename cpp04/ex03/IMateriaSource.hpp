/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:46:55 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/11 18:52:43 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
	protected:
		AMateria *material[4];
	public:
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria* mat) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};