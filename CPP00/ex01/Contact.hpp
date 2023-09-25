/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:49:34 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/25 21:27:33 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Contact{
	private:
		std::string firstname;
		std::string	lastname;
		std::string nickname;
		std::string phonenumber;
		std::string darkest_secret;
	public:
		void		display_less(int idx);
		void		display_all();
		void		add();
};

void	format_print(std::string str, std::string end){
	if (str.length() <= 10){
		std::cout << std::setw(10) << std::right << str << end;
		return ;
	}
	std::cout << str.substr(0, 9);
	std::cout << "." << end;
};

void Contact::display_less(int idx){
	format_print(std::to_string(idx), "|");
	format_print(this->firstname, "|");
	format_print(this->lastname, "|");
	format_print(this->nickname, "\n");
};

void Contact::display_all(){
	std::cout << std::setw(41) << std::setfill('-') << "\n" << std::setfill( ' ');
	std::cout << std::setw(20) << std::right << "Firstname is: ";
	std::cout << std::setw(20) << std::right << this->firstname << "\n";
	std::cout << std::setw(20) << std::right << "Lastname is: ";
	std::cout << std::setw(20) << std::right << this->lastname << "\n";
	std::cout << std::setw(20) << std::right << "Nickname is: ";
	std::cout << std::setw(20) << std::right << this->nickname << "\n";
	std::cout << std::setw(20) << std::right << "Phone Num is: ";
	std::cout << std::setw(20) << std::right << this->phonenumber<< "\n";
	std::cout << std::setw(20) << std::right << "Darkest Secret is: ";
	std::cout << std::setw(20) << std::right << this->darkest_secret<< "\n";
	std::cout << std::setw(41) << std::setfill('-') << "\n" << std::setfill( ' ');
	std::cout << "\n";
}

class PhoneBook{
	public:
		void	search(void);
		void	add(void);
		PhoneBook(){
			this->total = 0;
		}
	private:
		int		total;
		Contact book[8];
};


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
	if (command.length() == 1 && command[0] >= '1' && command[1] <= '8'){
		this->book[command[0] - '1'].display_all();
	}
};

void	Contact::add(void){
	while (1){	
	std::cout << "first name is...\n";
	std::cin >> this->firstname;
	if (this->firstname.length()) break;
	std::cout << "Try again: field is empty\n";
	}
	while (1){	
	std::cout << "lastname is...\n";
	std::cin >> this->lastname;
	if (this->lastname.length()) break;
	std::cout << "Try again: field is empty\n";
	}
	while (1){	
	std::cout << "nickname is...\n";
	std::cin >> this->nickname;
	if (this->nickname.length()) break;
	std::cout << "Try again: field is empty\n";
	}
	while (1){	
	std::cout << "phone number is...\n";
	std::cin >> this->phonenumber;
	if (this->phonenumber.length()) break;
	std::cout << "Try again: field is empty\n";
	}
	while (1){	
	std::cout << "darkest_secret is...\n";
	std::cin >> this->darkest_secret;
	if (this->darkest_secret.length()) break;
	std::cout << "Try again: field is empty\n";
	}
}

void	PhoneBook::add(void){
	std::string	command;
	int idx;
	
	idx = (this->total) % 8 ;
	this->book[idx].add();
	this->total += 1;
};
