/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:08:43 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 14:32:16 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.class.hpp"
#include <ctime>
#include <iostream>

//	******************
// 	OPERATION SECTION
//	******************
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	this->_nbDeposits++;
	std::cout	<< "index:" << this->_accountIndex << ';'\
				<<"p_amount:" << this->checkAmount() << ';';
	this->_amount += deposit;
	std::cout 	<< "deposit:" << deposit << ';'\
				<< "amount:" << this->checkAmount() << ';'\
				<< "nb_deposits:" << this->_nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals++;
		std::cout	<< "index:" << this->_accountIndex << ';'\
					<< "p_amount:" << this->checkAmount() << ';';
		this->_amount -= withdrawal;
		std::cout	<< "withdrawal:" << withdrawal << ';'\
					<< "amount:" << this->checkAmount() << ';'\
					<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	else
	{
		std::cout	<< "index:" << this->_accountIndex << ';'\
					<< "p_amount:" << this->checkAmount() << ';'\
					<< "withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ';'\
				<< "amount:" << this->checkAmount() << ';'\
				<< "deposits:" << this->_nbDeposits << ';'\
				<< "withdrawals:" << this->_nbWithdrawals\
				<< std::endl;
}


//	************
// 	GET SECTION
//	************

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

//	****************
// 	DISPLAY SECTION
//	****************

void Account::_displayTimestamp(void)
{
	char date[20] = { 0 };
	time_t time = std::time(NULL);

	std::strftime(date, 15, "%Y%m%d_%H%M%S" , std::localtime(&time));
	std::cout << "[" << date << "] ";
	return;
}


void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";"\
				<< "total:" << getTotalAmount() << ";"\
				<< "deposits:" << getNbDeposits() << ";"\
				<< "withdrawals:" << getNbWithdrawals()\
				<< std::endl;
}

//	*******************************
// 	CONSTRUCTOR/DESTRUCTOR SECTION
//	*******************************
Account::Account(int initial_deposit ): _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ';'\
				<< "amount:" << initial_deposit << ';'\
				<< "created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	return;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ';'\
				<< "amount:" << this->_amount << ';'\
				<< "closed" << std::endl;
	_nbAccounts--;
	return;
}

Account::Account(void)
{
	return;
}

// INIT SECTION
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;



// Walkthrough

//	Need to init. DONE
//	static int	_nbAccounts;
//	static int	_totalAmount;
//	static int	_totalNbDeposits;
//	static int	_totalNbWithdrawals;
// ----------------------------------

//	Get Section DONE
//	static int	getNbAccounts( void );
//	static int	getTotalAmount( void );
//	static int	getNbDeposits( void );
//	static int	getNbWithdrawals( void );

//	Display Section Done
//	static void	displayAccountsInfos( void );
//	static void	_displayTimestamp( void );

//	Operation Section Done
	// void	makeDeposit( int deposit );
	// bool	makeWithdrawal( int withdrawal );
	// int		checkAmount( void ) const;
	// void	displayStatus( void ) const;
