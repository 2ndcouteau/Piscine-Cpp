/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:53:57 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 21:05:58 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// CONSTRUTORS / DESTRUCTORS
FragTrap::FragTrap(void)
{
	std::cout << " FragTrap Default Constructor " << std::endl;
}

FragTrap::FragTrap(std::string name) :
ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5, 25)
{
	std::cout << " FragTrap Default Constructor : Hellooo, VaultHunter, and thank you for answering Hyperion's summons! " << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << " FragTrap Copy Constructor " << std::endl;
	*this = src;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << " FragTrap Destructor : Save Me! Save Me! Oops too late, I'm DEAD. TT" << std::endl;
	return;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string	attacks[5] = {
		"Brra, Dildo in your face !",
		"Brrr Brrr Brrr Kalash Kalash!",
		"Toi et Moi, Octogone, pas d'arbitre...",
		"I am gonna Clap Clap Clap your Ass Ass Ass !",
		"MegaPunchOfTheDeath !"
	};


	if (this->_energy_points < this->_energy_cost_attack)
		std::cout << "Not enough energy point to attack." << std::endl;
	else
	{
		this->_energy_points -= this->_energy_cost_attack;
		std::cout << "Valhunter's attack on " << target << ": \"" << attacks[std::rand() % 5] << "\"" << std::endl;
	}
}

FragTrap&		FragTrap::operator=(FragTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return(*this);
}
