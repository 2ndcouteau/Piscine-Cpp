/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 21:25:44 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 22:17:35 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
		Character(void);

	protected:
		std::string		_name;
		int				_ap;
		int				_max_ap;
		AWeapon			*_weapon;


	public:
		Character(std::string const & name);
		Character(Character const &src);
		virtual ~Character(void);


		void 			recoverAP();
		void 			equip(AWeapon*);
		void 			attack(Enemy*);

		std::string		getInfos(void) const;

		std::string const &	getName(void) const;
		int				getAp(void) const;
		int				getMaxAp(void) const;
		AWeapon*		getWeapon(void) const;

		Character &	operator=(Character const &rhs);
};

std::ostream &	operator<<(std::ostream &o, Character const &rhs);

#endif
