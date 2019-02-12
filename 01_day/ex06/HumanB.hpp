/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:17:05 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/09 19:02:23 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_CLASS_HPP
# define HUMAN_B_CLASS_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*_weapon;
		std::string	_name;


	public:
		HumanB(std::string name);
		~HumanB(void);

		void	attack() const;
		void	setWeapon(Weapon &weapon);
};


#endif
