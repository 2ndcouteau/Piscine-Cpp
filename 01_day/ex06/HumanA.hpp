/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:17:05 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/09 18:59:53 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_CLASS_HPP
# define HUMAN_A_CLASS_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon		&_weapon;
		std::string	_name;


	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void	attack() const;
};


#endif
