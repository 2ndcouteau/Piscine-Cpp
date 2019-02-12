/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:00:35 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 21:22:36 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <sstream>

Enemy::Enemy(void) : _hp(0), _type("undefined")
{
//	std::cout << " Enemy Default Constructor " << std::endl;
	return;
}

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type)
{
	return;
}

Enemy::Enemy(Enemy const &src)
{
//	std::cout << " Enemy Copy Constructor " << std::endl;
	*this = src;
	return;
}

Enemy::~Enemy(void)
{
//	std::cout << " Enemy Destructor " << std::endl;
	return;
}

void Enemy::takeDamage(int damage)
{
	if (!(damage < 0))
	{
		if (this->getHP() < damage)
		{
			std::cout << "The " << this->getType() << " looses " << this->getHP() << " HP." << std::endl;
			this->_hp = 0;
		}
		else
		{
			std::cout << "The " << this->getType() << " looses " << damage << " HP." << std::endl;
			this->_hp  -= damage;
		}
	}
	else
		std::cout << "The attack is too weak, nothing happened." << std::endl;

	return;
}




// GET SET
std::string const &		Enemy::getType(void) const
{
	return (this->_type);
}


int				Enemy::getHP() const
{
	return (this->_hp);
}

static std::string		to_string(int value)
{
	std::ostringstream os ;

	os << value ;

	return (os.str());
}

std::string		Enemy::getInfos(void) const
{
	std::string str;

	str = "It is a " + this->getType() + ". It has " + to_string(this->getHP()) + " HP.\n";
	return (str);
}



// OVERLOAD OPERATOR
std::ostream&	operator<<(std::ostream& o, Enemy const & rhs)
{
	o << rhs.getInfos();
	return (o);
}

Enemy &	Enemy::operator=(Enemy const &rhs)
{
	//	std::cout << " Enemy Assignement Operator " << std::endl;

	if (this != &rhs)
	{
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
	}
	return *this;
}
