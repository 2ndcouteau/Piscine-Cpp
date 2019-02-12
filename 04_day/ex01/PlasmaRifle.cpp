/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:48:07 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 22:25:39 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21)
{
//	std::cout << " AWeapon Default Constructor " << std::endl;
	return;
}


PlasmaRifle::PlasmaRifle(PlasmaRifle const &src)
{
//	std::cout << " PlasmaRifle Copy Constructor " << std::endl;
	*this = src;
	return;
}

PlasmaRifle::~PlasmaRifle(void)
{
//	std::cout << " PlasmaRifle Destructor " << std::endl;
	return;
}

PlasmaRifle &	PlasmaRifle::operator=(PlasmaRifle const &rhs)
{
	return *this;
}

void 			PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
	return;
}
