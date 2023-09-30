/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:57:54 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/30 11:13:32 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};

void Harl::debug( void ) {
	std::cout << BOLDBLUE << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET<< std::endl;
}
void Harl::info( void ) {
	std::cout << BOLDGREEN << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}
void Harl::warning( void ) {
	std::cout << BOLDYELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." <<RESET << std::endl;
}
void Harl::error( void ) {
	std::cout << BOLDRED << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void Harl::complain(std::string level){
	int i;
	void (Harl::*func[4])(void) = {
			&Harl::debug, 
			&Harl::info, 
			&Harl::warning, 
			&Harl::error
		};
		
	std::string const command[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};

	for (i = 0; i < 4; i++){
		if (command[i] == level)
			return ((this->*func[i])());
	}
	if (i == 4)
		std::cout << "That's not harl's command. Try again.\n";
}