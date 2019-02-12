/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:53:57 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 15:53:18 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// CONSTRUTORS / DESTRUCTORS
FragTrap::FragTrap(void)
{
	std::cout << " FragTrap Default Constructor " << std::endl;
}

FragTrap::FragTrap(std::string name) :
_name(name),
_hit_points(100),
_max_hit_points(100),
_energy_points(100),
_max_energy_points(100),
_level(1),
_melee_attack_damage(30),
_ranged_attack_damage(20),
_armor_damage_reduction(5),
_energy_cost_attack(25)
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

FragTrap &	FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << " FragTrap Assignement Operator " << std::endl;

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
void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_ranged_attack_damage << " points of damage !" << std::endl;
	return;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_melee_attack_damage << " points of damage !" << std::endl;
	return;
}

void	FragTrap::takeDamage(unsigned int amount)
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

void	FragTrap::beRepaired(unsigned int amount)
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

std::size_t	FragTrap::getHitPoints() const
{
	return (this->_hit_points);
}

std::size_t FragTrap::getMaxHitPoints() const
{
	return (this->_max_hit_points);
}

std::size_t	FragTrap::getMeleeAttack() const
{
	return (this->_melee_attack_damage);
}

std::size_t	FragTrap::getRangedAttack() const
{
	return (this->_ranged_attack_damage);
}


std::size_t FragTrap::getEnergyPoints() const
{
	return (this->_energy_points);
}

std::size_t FragTrap::getMaxEnergyPoints() const
{
	return (this->_max_energy_points);
}

std::size_t FragTrap::getLevel() const
{
	return (this->_level);
}

std::size_t FragTrap::getArmorDamageReduction() const
{
	return (this->_armor_damage_reduction);
}

std::size_t FragTrap::getEnergyCostAttack() const
{
	return (this->_energy_cost_attack);
}

std::string FragTrap::getName() const
{
	return (this->_name);
}




void		FragTrap::display_profile(void) const
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
