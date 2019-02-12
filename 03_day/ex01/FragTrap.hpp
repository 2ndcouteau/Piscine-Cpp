/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:54:16 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 15:37:35 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_CLASS_HPP
# define FRAG_TRAP_CLASS_HPP

#include <iostream>

class FragTrap
{
	private:
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

	protected:


	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap &	operator=(FragTrap const &rhs);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void 	vaulthunter_dot_exe(std::string const & target);

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

// std::ostream &	operator<<(std::ostream &o, FragTrap const &i);

#endif
