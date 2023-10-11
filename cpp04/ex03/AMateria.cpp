/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:48:00 by siwolee           #+#    #+#             */
/*   Updated: 2023/10/10 21:23:53 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){};

AMateria::AMateria(std::string const & type) : type(type) {};

std::string const & AMateria::getType() const{
	return (this->type);
}

