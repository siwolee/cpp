/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:56:45 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/27 15:23:52 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		Harl();
		void complain(std::string level);
};

void Harl::complain(std::string level){
	void (Harl::*func[4])(void) = {
		Harl::debug, 
		Harl::info, 
		Harl::warning, 
		Harl::error
	};

	std::string const command[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};

	for (int i = 0; i < 4; i++){
		if (command[i] == level)
			func[i]();
	}
}