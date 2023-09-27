/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:54:17 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/25 21:58:18 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include "Contact.hpp"

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