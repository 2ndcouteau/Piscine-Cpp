/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:57:08 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 21:24:28 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"


RadScorpion::RadScorpion(void) : Enemy(80, "Rad Scorpion")
{
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::RadScorpion(RadScorpion const &src)
{
//	std::cout << " RadScorpion Copy Constructor " << std::endl;
	*this = src;
	return;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "“* SPROTCH *" << std::endl;
	return;
}

RadScorpion &	RadScorpion::operator=(RadScorpion const &rhs)
{
	Enemy::operator=(rhs);
	return (*this);
}
