/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:50:26 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 15:46:13 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"


Sorcerer::Sorcerer(void)
{
//	std::cout << " Sorcerer Default Constructor " << std::endl;
	return;
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
//	std::cout << " Sorcerer Copy Constructor " << std::endl;
	*this = src;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
	return;
}


std::string		Sorcerer::introduce(void) const
{
	std::string str;

	str = "I am " + this->getName() + ", " + this->getTitle() + ", and I like ponies !\n";
	return (str);
}

void 		Sorcerer::polymorph(Victim const &rhs) const
{
	rhs.getPolymorphed();
	return;
}


// Get Set
std::string const &	Sorcerer::getName(void) const
{
	return (this->_name);
}

std::string const &	Sorcerer::getTitle(void) const
{
	return (this->_title);
}


// Overload operator
Sorcerer &	Sorcerer::operator=(Sorcerer const &rhs)
{
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, Sorcerer const & rhs)
{
	o << rhs.introduce();
	return (o);
}
