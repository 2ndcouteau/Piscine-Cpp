/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:51:05 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 15:45:30 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"


Victim::Victim(void)
{
//	std::cout << " Victim Default Constructor " << std::endl;
	return;
}

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called " << this->getName() << " just popped !" << std::endl;

	return;
}

Victim::Victim(Victim const &src)
{
//	std::cout << " Victim Copy Constructor " << std::endl;
	*this = src;
	return;
}


Victim::~Victim(void)
{
	std::cout << "Victim " << this->getName() << " just died for no apparent reason !" << std::endl;
	return;
}

std::string		Victim::introduce(void) const
{
	std::string str;

	str = "I am " + this->getName() + " and I like otters !\n";
	return (str);
}


void 		Victim::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
	return;
}

// Get Set
std::string const &		Victim::getName(void) const
{
	return (this->_name);
}


// Overload Operator
Victim &	Victim::operator=(Victim const &rhs)
{
	this->_name = rhs.getName();
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, Victim const & rhs)
{
	o << rhs.introduce();
	return (o);
}
