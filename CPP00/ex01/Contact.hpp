/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:49:34 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/25 22:05:44 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>

void	format_print(std::string str, std::string end);

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


