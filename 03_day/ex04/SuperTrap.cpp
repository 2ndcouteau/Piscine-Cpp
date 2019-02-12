/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:31:49 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 23:39:37 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

// CONSTRUTORS / DESTRUCTORS
SuperTrap::SuperTrap(void) : ClapTrap("SuperNULL", 100, 100, 120, 120, 1, 60, 20, 5, 25)
{
	std::cout << " SuperTrap Default Constructor : Call me Super Jonh Doe !" << std::endl;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5, 25)
{
	std::cout << " SuperTrap Default Constructor : Go away, the king is there !" << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap const &src)
{
	std::cout << " SuperTrap Copy Constructor " << std::endl;
	*this = src;
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << " SuperTrap Destructor : Why ?? I was the BEST OF THE WORLD !!!!" << std::endl;
	return;
}

SuperTrap&		SuperTrap::operator=(SuperTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return(*this);
}
