/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 21:25:46 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 22:59:58 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <sstream>

Character::Character(void)
{
	//	std::cout << " Character Default Constructor " << std::endl;
	return;
}

Character::Character(std::string const & name) : _name(name), _ap(40), _weapon(NULL), _max_ap(40)
{
//	std::cout << " Character Default Constructor " << std::endl;
	return;
}

Character::Character(Character const &src)
{
//	std::cout << " Character Copy Constructor " << std::endl;
	*this = src;
	return;
}

Character::~Character(void)
{
//	std::cout << " Character Destructor " << std::endl;
	return;
}

Character &	Character::operator=(Character const &rhs)
{
//	std::cout << " Character Assignement Operator " << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_ap = rhs.getAp();
		this->_ap = rhs.getMaxAp();
		this->_weapon = rhs.getWeapon();
	}
	return *this;
}

void Character::recoverAP()
{
	if ((this->getMaxAp() - this->getAp()) > 10)
		this->_ap += 10;
	else
		this->_ap = this->getMaxAp();
	std::cout << this->getName() << " recovered AP." << std::endl;
	return;
}

void	Character::equip(AWeapon* new_weapon)
{
	this->_weapon = new_weapon;
	return;
}

void	Character::attack(Enemy* target)
{
	if (this->_weapon != NULL)
	{
		if (this->getAp() >= this->_weapon->getAPCost())
		{
			this->_ap -= this->_weapon->getAPCost();
			std::cout << this->getName() << " attacks " << target->getType() << " with a " << this->_weapon->getName() << std::endl;
			this->_weapon->attack();
			target->takeDamage(this->_weapon->getDamage());
			if (target->getHP() <= 0)
				delete target;
			return;
		}
		std::cout << "Not enough AP." << std::endl;
		return;
	}
	std::cout << this->getName() << " is unarmed." << std::endl;
}


AWeapon*				Character::getWeapon(void) const
{
	return (this->_weapon);
}

std::string const &		Character::getName(void) const
{
	return (this->_name);
}

int						Character::getAp(void) const
{
	return (this->_ap);
}

int						Character::getMaxAp(void) const
{
	return (this->_max_ap);
}



static std::string		to_string(int value)
{
	std::ostringstream os ;

	os << value ;

	return (os.str());
}

std::string		Character::getInfos(void) const
{
	std::string str;

	if (this->_weapon != NULL)
		str = this->getName() + " has " +  to_string(this->getAp()) + " AP and wields a " + this->_weapon->getName() + ".\n";
	else
		str = this->getName() + " has " +  to_string(this->getAp()) + " AP and is unarmed.\n";
	return (str);
}

std::ostream&	operator<<(std::ostream& o, Character const & rhs)
{
	o << rhs.getInfos();
	return (o);
}
