/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:04:02 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 23:03:03 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	_name("No name"),
	_hit_points(1),
	_max_hit_points(1),
	_energy_points(1),
	_max_energy_points(1),
	_level(1),
	_melee_attack_damage(1),
	_ranged_attack_damage(1),
	_armor_damage_reduction(1),
	_energy_cost_attack(1)
{
	std::cout << " ClapTrap Default Constructor " << std::endl;
}

ClapTrap::ClapTrap(	std::string name,
					std::size_t hit_points,
					std::size_t max_hit_points,
					std::size_t energy_points,
					std::size_t max_energy_points,
					std::size_t level,
					std::size_t melee_attack_damage,
					std::size_t ranged_attack_damage,
					std::size_t armor_damage_reduction,
					std::size_t energy_cost_attack ) :
	_name(name),
	_hit_points(hit_points),
	_max_hit_points(max_hit_points),
	_energy_points(energy_points),
	_max_energy_points(max_energy_points),
	_level(level),
	_melee_attack_damage(melee_attack_damage),
	_ranged_attack_damage(ranged_attack_damage),
	_armor_damage_reduction(armor_damage_reduction),
	_energy_cost_attack(energy_cost_attack)
{
	std::cout << " ClapTrap Default Constructor : I am a Clap Trap, a true one" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << " ClapTrap Copy Constructor " << std::endl;
	*this = src;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << " ClapTrap Destructor : ClapTrap has something to say: \"Hasta la vista baby.\"" << std::endl;
	return;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << " ClapTrap Assignement Operator " << std::endl;

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
void	ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << ": Range attack on " << target << ". " << this->_ranged_attack_damage << " points of damage !" << std::endl;
	return;
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << ": Melee attack on " << target << ". " << this->_melee_attack_damage << " points of damage !" << std::endl;
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
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

void	ClapTrap::beRepaired(unsigned int amount)
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

// GET / SET
std::size_t	ClapTrap::getHitPoints() const
{
	return (this->_hit_points);
}

std::size_t ClapTrap::getMaxHitPoints() const
{
	return (this->_max_hit_points);
}

std::size_t	ClapTrap::getMeleeAttack() const
{
	return (this->_melee_attack_damage);
}

std::size_t	ClapTrap::getRangedAttack() const
{
	return (this->_ranged_attack_damage);
}


std::size_t ClapTrap::getEnergyPoints() const
{
	return (this->_energy_points);
}

std::size_t ClapTrap::getMaxEnergyPoints() const
{
	return (this->_max_energy_points);
}

std::size_t ClapTrap::getLevel() const
{
	return (this->_level);
}

std::size_t ClapTrap::getArmorDamageReduction() const
{
	return (this->_armor_damage_reduction);
}

std::size_t ClapTrap::getEnergyCostAttack() const
{
	return (this->_energy_cost_attack);
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}




void		ClapTrap::display_profile(void) const
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
