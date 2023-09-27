/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:56:45 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/27 16:58:09 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

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
