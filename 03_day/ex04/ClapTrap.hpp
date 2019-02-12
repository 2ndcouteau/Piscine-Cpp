/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:04:04 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 20:59:14 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_CLASS_HPP
# define CLAP_TRAP_CLASS_HPP

#include <iostream>

class ClapTrap
{
	private:

	protected:
		std::string	_name;
		std::size_t	_hit_points;
		std::size_t	_max_hit_points;
		std::size_t	_energy_points;
		std::size_t	_max_energy_points;
		std::size_t	_level;
		std::size_t _melee_attack_damage;
		std::size_t _ranged_attack_damage;
		std::size_t _armor_damage_reduction;
		std::size_t _energy_cost_attack;

	public:
		ClapTrap(void);
		ClapTrap(	std::string name,
					std::size_t hit_points,
					std::size_t max_hit_points,
					std::size_t energy_points,
					std::size_t max_energy_points,
					std::size_t level,
					std::size_t melee_attack_damage,
					std::size_t ranged_attack_damage,
					std::size_t armor_damage_reduction,
					std::size_t energy_cost_attack );

		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const &rhs);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	display_profile(void) const;

	// Get / Set
		std::string getName() const;
		std::size_t	getHitPoints() const;
		std::size_t getMaxHitPoints() const;
		std::size_t getEnergyPoints() const;
		std::size_t getMaxEnergyPoints() const;
		std::size_t getLevel() const;
		std::size_t	getMeleeAttack() const;
		std::size_t	getRangedAttack() const;
		std::size_t getArmorDamageReduction() const;
		std::size_t getEnergyCostAttack() const;
};

//std::ostream &	operator<<(std::ostream &o, ClapTrap const &i);

#endif
