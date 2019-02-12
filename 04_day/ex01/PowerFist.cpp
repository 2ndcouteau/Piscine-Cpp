/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:56:38 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 22:25:50 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"


PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{
//	std::cout << " PowerFist Default Constructor " << std::endl;
	return;
}

PowerFist::PowerFist(PowerFist const &src)
{
//	std::cout << " PowerFist Copy Constructor " << std::endl;
	*this = src;
	return;
}

PowerFist::~PowerFist(void)
{
//	std::cout << " PowerFist Destructor " << std::endl;
	return;
}

PowerFist &	PowerFist::operator=(PowerFist const &rhs)
{
//	std::cout << " PowerFist Assignement Operator " << std::endl;

//	if (this != &rhs)
//		this->_foo = rhs.getFoo();

	return *this;
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
	return;
}
