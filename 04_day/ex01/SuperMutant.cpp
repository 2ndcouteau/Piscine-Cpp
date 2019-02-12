/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:21:43 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 21:23:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"


SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant"), _armor(3)
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::SuperMutant(SuperMutant const &src)
{
//	std::cout << " SuperMutant Copy Constructor " << std::endl;
	*this = src;
	return;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
	return;
}

SuperMutant &	SuperMutant::operator=(SuperMutant const &rhs)
{
	if (this != &rhs)
	{
		Enemy::operator=(rhs);
		this->_armor = rhs.getArmor();
	}
	return (*this);
}

void 	SuperMutant::takeDamage(int damage)
{
	Enemy::takeDamage(damage - this->getArmor());
	return;
}


// GET SET
int		SuperMutant::getArmor() const
{
	return (this->_armor);
}
