/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:48:17 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 22:00:20 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMA_RIFLE_CLASS_HPP
# define PLASMA_RIFLE_CLASS_HPP

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	private:
		PlasmaRifle &	operator=(PlasmaRifle const &rhs);

	protected:


	public:
		PlasmaRifle(void);
		PlasmaRifle(PlasmaRifle const &src);
		~PlasmaRifle(void);


		void attack(void) const;

};

#endif
