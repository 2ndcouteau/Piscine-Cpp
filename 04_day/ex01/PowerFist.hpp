/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:56:36 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 20:04:52 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWER_FIST_CLASS_HPP
# define POWER_FIST_CLASS_HPP

#include <iostream>
#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	private:
		PowerFist &	operator=(PowerFist const &rhs);

	protected:


	public:
		PowerFist(void);
		PowerFist(PowerFist const &src);
		~PowerFist(void);


		void attack() const;
};

#endif
