/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:49:14 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/25 22:07:20 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::search(void) {
	std::string	command;

	if (this->total == 0){
		std::cout << "phonebook is empty\n";
		return ;
	}
	for (int i = 0; i < total && i < 8; i++){
		(this->book)[i].display_less(i + 1);
	}
	std::cin >> command;
	if (command.length() == 1 && command[0] >= '1' && command[0] <= '8'){
		this->book[command[0] - '1'].display_all();
	}
};

void	PhoneBook::add(void){
	std::string	command;
	int idx;
	
	idx = (this->total) % 8 ;
	this->book[idx].add();
	this->total += 1;
};



