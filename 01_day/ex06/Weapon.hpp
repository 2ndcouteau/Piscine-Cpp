/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:25:08 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/09 18:32:20 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <iostream>

class Weapon
{
	private:
		std::string		_type;

	public:
		Weapon(std::string	weapon_type);
		~Weapon(void);

		std::string&	getType() const;
		void			setType(std::string	type);
};

#endif
