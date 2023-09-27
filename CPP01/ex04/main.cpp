/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:56:29 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/26 21:56:30 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main (int ac, char **av)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	char			c;
	std::string		newname = av[1];
	int				i;

	if (ac != 4){
		std::cerr << "input must be 3 : filename and 2 strings\n";
		return (-1);
	}
	ifs.open(av[1], std::ios::in);
	if (!ifs){
		std::cerr << "input file is unvlid\n";
		return (-1);
	}
	newname.append(".replace");
	ofs.open(newname, std::ios::out | std::ios::trunc);
	if (ofs.fail()){
		std::cerr << "output file is unvlid\n";
		return (-1);
	}
	while (ifs.get(c)){
		if (c == av[2][0]){
			i = 1;
			while (av[2][i] && ifs.get(c) && c == av[2][i])
				i++;
			if (av[2][i] == 0){
				ofs << av[3];
			}
			else {
				for (int e = 0; e < i ; e++){
				ofs.put(av[2][e]);
				}
			}		
		}
		else{
			ofs.put(c);
		}
	}
	return (0);
}