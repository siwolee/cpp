/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:49:14 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/25 21:24:10 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

int main()
{
	std::string	command;
	PhoneBook	pb;

	while (1)
	{
		std::cout<<"---This is so PhoneBook---\n";
		std::cin>>command;
		if (command.compare("add") == 0)
		{
			pb.add();
		}
		else if (command.compare("search") == 0)
		{
			pb.search();
		}
		else if (command.compare("exit") == 0)
		{
			std::cout << "exit phonebook\n";
			break;
		}
	}
	return (0);
}

