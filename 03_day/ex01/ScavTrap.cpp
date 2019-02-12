/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:44:59 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 18:01:57 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << " ScavTrap Default Constructor " << std::endl;
}


ScavTrap::ScavTrap(std::string name) :
_name(name),
_hit_points(100),
_max_hit_points(100),
_energy_points(50),
_max_energy_points(50),
_level(1),
_melee_attack_damage(20),
_ranged_attack_damage(15),
_armor_damage_reduction(3),
_energy_cost_attack(25)
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

ScavTrap &	ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << " ScavTrap Assignement Operator " << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hit_points = rhs.getHitPoints();
		this->_max_hit_points = rhs.getMaxHitPoints();
		this->_energy_points = rhs.getEnergyPoints();
		this->_max_energy_points = rhs.getMaxEnergyPoints();
		this->_level = rhs.getLevel();
		this->_melee_attack_damage = rhs.getMeleeAttack();
		this->_ranged_attack_damage = rhs.getRangedAttack();
		this->_armor_damage_reduction = rhs.getArmorDamageReduction();
		this->_energy_cost_attack = rhs.getEnergyCostAttack();
	}
	return *this;
}



// ATTACKS FUNCTIONS
void	ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << ": Range attack on " << target << ". " << this->_ranged_attack_damage << " points of damage !" << std::endl;
	return;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << ": Melee attack on " << target << ". " << this->_melee_attack_damage << " points of damage !" << std::endl;
	return;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (amount <= _armor_damage_reduction)
	{
		std::cout << "FR4G-TP " << this->_name << " received no degats" << std::endl;
		return;
	}
	amount -= this->_armor_damage_reduction;

	std::cout << "FR4G-TP " << this->_name << " received " << amount << " an attack." << std::endl;
	if (amount < this->_hit_points)
		this->_hit_points -= amount;
	else
	{
		this->_hit_points = 0;
		std::cout << "FR4G-TP " << this->_name << " dies..." << std::endl;
	}
	return;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (amount == 0)
	{
		std::cout << "FR4G-TP " << this->_name << " has not been repaired. Try again !" << std::endl;
		return;
	}
	std::cout << "FR4G-TP " << this->_name << " is repaired." << "He gains " << amount << " Hp!" << std::endl;
	if ((this->_hit_points + amount) > this->_max_hit_points)
		this->_hit_points = this->_max_hit_points;
	else
		this->_hit_points += amount;
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

std::size_t	ScavTrap::getHitPoints() const
{
	return (this->_hit_points);
}

std::size_t ScavTrap::getMaxHitPoints() const
{
	return (this->_max_hit_points);
}

std::size_t	ScavTrap::getMeleeAttack() const
{
	return (this->_melee_attack_damage);
}

std::size_t	ScavTrap::getRangedAttack() const
{
	return (this->_ranged_attack_damage);
}


std::size_t ScavTrap::getEnergyPoints() const
{
	return (this->_energy_points);
}

std::size_t ScavTrap::getMaxEnergyPoints() const
{
	return (this->_max_energy_points);
}

std::size_t ScavTrap::getLevel() const
{
	return (this->_level);
}

std::size_t ScavTrap::getArmorDamageReduction() const
{
	return (this->_armor_damage_reduction);
}

std::size_t ScavTrap::getEnergyCostAttack() const
{
	return (this->_energy_cost_attack);
}

std::string ScavTrap::getName() const
{
	return (this->_name);
}




void		ScavTrap::display_profile(void) const
{
	std::cout	<< "Profile:" << std::endl\
				<< "_name: " << this->_name << std::endl\
				<< "_hit_points: " << this->_hit_points << std::endl\
				<< "_max_hit_points: " << this->_max_hit_points << std::endl\
				<< "_energy_points: " << this->_energy_points << std::endl\
				<< "_max_energy_points: " << this->_max_energy_points << std::endl\
				<< "_level: " << this->_level << std::endl\
				<< "_melee_attack_damage: " << this->_melee_attack_damage << std::endl\
				<< "_ranged_attack_damage: " << this->_ranged_attack_damage << std::endl\
				<< "_armor_damage_reduction: " << this->_armor_damage_reduction << std::endl\
				<< "_energy_cost_attack: " << this->_energy_cost_attack << std::endl\
				<< std::endl;
}
