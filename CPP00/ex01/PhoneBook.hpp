/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:01 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/25 22:06:15 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
