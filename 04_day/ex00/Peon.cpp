/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:49:59 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 15:55:55 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"


Peon::Peon(void)
{
//	std::cout << " Peon Default Constructor " << std::endl;
	return;
}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return;
}


Peon::Peon(Peon const &src) : Victim(src)
{
//	std::cout << " Peon Copy Constructor " << std::endl;
	*this = src;
	return;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark.." << std::endl;
	return;
}

Peon &	Peon::operator=(Peon const &rhs)
{
	*this = rhs;
	return (*this);
}


void	Peon::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
	return;
}
