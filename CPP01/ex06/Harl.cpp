/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:57:54 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/27 17:54:59 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};

void Harl::debug( void ) {
	std::cout << "[ DEBUG ]\n";
	std::cout << BOLDBLUE << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n" << RESET;
}
void Harl::info( void ) {
	std::cout << "[ INFO ]\n";
	std::cout << BOLDGREEN << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n" << RESET;
}
void Harl::warning( void ) {
	std::cout << "[ WARNING ]\n";
	std::cout << BOLDYELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n" <<RESET;
}
void Harl::error( void ) {
	std::cout << "[ ERROR ]\n";
	std::cout << BOLDRED << "This is unacceptable! I want to speak to the manager now.\n\n" << RESET;
}

void Harl::complain(std::string level){
	int i;
	std::string const command[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};

	for (i = 0; i < 4; i++){
		if (command[i] == level)
			break;
	}
	
	switch (i)
	{
	case 0:
		this->debug();
	case 1:
		this->info();
	case 2:
		this->warning();
	case 3:
		this->error();
	default:
		break;
	}
}