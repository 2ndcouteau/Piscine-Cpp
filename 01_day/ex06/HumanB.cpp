/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:16:27 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/09 19:13:03 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack() const
{
	std::cout	<< this->_name\
	 			<< " attacks with his "\
				<< this->_weapon->getType()\
				<< std::endl;
}

HumanB::HumanB(std::string name) : _name(name)
{
//	std::cout << " HumanB Constructor " << std::endl;
	return;
}

HumanB::~HumanB(void)
{
//	std::cout << " HumanB Destructor " << std::endl;
	return;
}
