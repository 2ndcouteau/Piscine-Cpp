/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:00:22 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 22:06:32 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_CLASS_HPP
# define AWEAPON_CLASS_HPP

#include <iostream>

class AWeapon
{
	private:

	protected:
		AWeapon(void);
		std::string		_name;
		int				_damage;
		int				_apcost;

	public:
		AWeapon(AWeapon const &src);
		AWeapon(std::string const & name, int apcost, int damage);
		virtual ~AWeapon();

		virtual void attack() const = 0;


// GET SET
		std::string const & getName(void) const;

		int			getDamage(void) const;
		void		setDamage(int damage);

		void		setAPCost(int apcost);
		int 		getAPCost(void) const;

		std::string	getInfos(void) const;


		AWeapon &	operator=(AWeapon const &rhs);

};

std::ostream &	operator<<(std::ostream &o, AWeapon const &rhs);

#endif
