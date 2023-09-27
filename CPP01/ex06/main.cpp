/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:56:20 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/27 17:01:00 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char *av[])
{
	Harl harl;

	if (ac != 2)
	{
		std::cerr << "Harl needs command\n";
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}