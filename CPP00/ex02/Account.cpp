/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:33:43 by siwolee           #+#    #+#             */
/*   Updated: 2023/09/25 21:41:45 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

//public
	// bool	makeWithdrawal( int withdrawal );
	// int		checkAmount( void ) const;
	// void	displayStatus( void ) const;
	// static int	getNbAccounts( void );
	// static int	getTotalAmount( void );
	// static int	getNbDeposits( void );
	// static int	getNbWithdrawals( void );
	// static void	displayAccountsInfos( void );

Account(int initial_deposit){
	this->_nbAccounts += 1;
	this->_totalAmount += ini
	this->
}


void Account::makeDeposit(int deposit){
	this->_amount += deposit;
	this->_nbDeposits += 1;
};
