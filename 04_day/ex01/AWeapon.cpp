/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:03:31 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 20:51:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include <sstream>

AWeapon::AWeapon(void)
{
//	std::cout << " AWeapon Default Constructor " << std::endl;
	return;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
_name(name),
_apcost(apcost),
_damage(damage)
{
//	std::cout << " AWeapon Default Constructor " << std::endl;
	return;
}


AWeapon::AWeapon(AWeapon const &src)
{
//	std::cout << " AWeapon Copy Constructor " << std::endl;
	*this = src;
	return;
}

AWeapon::~AWeapon(void)
{
//	std::cout << " AWeapon Destructor " << std::endl;
	return;
}

// GET SET
std::string const & AWeapon::getName(void) const
{
	return (this->_name);
}


int AWeapon::getDamage() const
{
	return (this->_damage);
}

void	AWeapon::setDamage(int damage)
{
	if (damage > -1)
		this->_damage = damage;
	return;
}

int AWeapon::getAPCost(void) const
{
	return (this->_apcost);
}

void	AWeapon::setAPCost(int apcost)
{
	if (apcost > -1)
		this->_apcost = apcost;
	return;
}




static std::string		to_string(int value)
{
	std::ostringstream os ;

	os << value ;

	return (os.str());
}

std::string		AWeapon::getInfos(void) const
{
	std::string str;

	str = "This weapon is the " + this->getName() + ". It costs " + to_string(this->getAPCost()) + " AP to make " + to_string(this->getDamage()) + " damage points.\n";
	return (str);
}



// OVERLOAD OPERATOR
AWeapon &	AWeapon::operator=(AWeapon const &rhs)
{
//	std::cout << " AWeapon Assignement Operator " << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_damage = rhs.getDamage();
		this->_apcost = rhs.getAPCost();
	}
	return *this;
}


std::ostream&	operator<<(std::ostream& o, AWeapon const & rhs)
{
	o << rhs.getInfos();
	return (o);
}
