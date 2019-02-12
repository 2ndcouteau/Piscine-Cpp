/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:24:31 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/09 18:34:00 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string&	Weapon::getType() const
{
	return ((std::string &)this->_type);
}

void			Weapon::setType(std::string	type)
{
	this->_type = type;
	return;
}

Weapon::Weapon(std::string	weapon_type) : _type(weapon_type)
{
//	std::cout << " Weapon Constructor " << std::endl;
	return;
}

Weapon::~Weapon(void)
{
//	std::cout << " Weapon Destructor " << std::endl;
	return;
}
