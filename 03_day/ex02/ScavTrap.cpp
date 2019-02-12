/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:44:59 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 21:06:32 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << " ScavTrap Default Constructor " << std::endl;
}


ScavTrap::ScavTrap(std::string name) :
ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3, 25)
{
	std::cout << " ScavTrap Default Constructor : I know, Iknow, I am awesome at gate guarding, so I will Guard the Gate ^^ " << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << " ScavTrap Copy Constructor " << std::endl;
	*this = src;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << " ScavTrap Destructor : Even if I die, the Gate is still safe ... Good Bye." << std::endl;
	return;
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string	attacks[5] = {
		"Run 10km, do 100 pumps and 100 Jolly Jumper",
		"Visit the House of DrVculV",
		"Find a Unicorn",
		"Spartans What is your Profession ? Ahouh ! Ahouh ! Ahouh !, So become Badass as Fuck as These fucking Spatans",
		"Distortion temporal activated. CoMe On, I am WaItInG fOr YoU... Return in the Past and Kill Hitler PLZ",
	};


	if (this->_energy_points < this->_energy_cost_attack)
		std::cout << "Not enough energy point to attack." << std::endl;
	else
	{
		this->_energy_points -= this->_energy_cost_attack;
		std::cout << "Challenge on " << target << ": \"" << attacks[std::rand() % 5] << "\"" << std::endl;
	}
}

ScavTrap&		ScavTrap::operator=(ScavTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return(*this);
}
