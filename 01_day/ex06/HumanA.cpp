/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:16:27 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/09 18:59:44 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack() const
{
	std::cout	<< this->_name\
	 			<< " attacks with his "\
				<< this->_weapon.getType()\
				<< std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
//	std::cout << " HumanA Constructor " << std::endl;
	return;
}

HumanA::~HumanA(void)
{
//	std::cout << " HumanA Destructor " << std::endl;
	return;
}
