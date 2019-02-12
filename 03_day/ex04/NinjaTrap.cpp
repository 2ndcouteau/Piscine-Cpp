/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:35:52 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 21:07:43 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap("Random Ninja", 60, 60, 120, 120, 1, 60, 5, 0, 25)
{
	std::cout << " NinjaTrap Default Constructor : Call me Jonh Doe !" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) :
ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0, 25)
{
	std::cout << " NinjaTrap Default Constructor : I am in the shadow..." << std::endl;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src)
{
	std::cout << " NinjaTrap Copy Constructor " << std::endl;
	*this = src;
	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << " NinjaTrap Destructor : Shame on me, I'm dying in public" << std::endl;
	return;
}

void	NinjaTrap::ninjaShoebox(FragTrap & frag)
{
	if (this->_energy_points < this->_energy_cost_attack)
		std::cout << "Not enough energy point to make an action" << std::endl;
	else
	{
		this->_energy_points -= this->_energy_cost_attack;

		std::cout << this->_name << " intimidates " << frag.getName() << " with his bilboquet skill." << std::endl;
	}
}

void	NinjaTrap::ninjaShoebox(ScavTrap & scav)
{
	std::cout << "I don't care about Little Pretty Holly Scav " << scav.getName() << ". I will not spend energy for \"that\" ..." << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & ninja)
{
	if (this->_energy_points < this->_energy_cost_attack)
		std::cout << "Not enough energy point to make an action" << std::endl;
	else
	{
		this->_energy_points -= this->_energy_cost_attack;

		std::cout << this->_name << " look his brother " << ninja.getName() << " with infatuation " << std::endl;
	}
}

NinjaTrap&		NinjaTrap::operator=(NinjaTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return(*this);
}
