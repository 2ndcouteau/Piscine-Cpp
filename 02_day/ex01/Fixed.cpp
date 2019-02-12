/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:01:54 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/10 18:43:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>

#include "Fixed.hpp"


const int Fixed::_fix = 8;


float		Fixed::toFloat(void) const
{
	return (_raw / (double)(1 << _fix));
}

int		Fixed::toInt(void) const
{
	return (_raw / (1 << _fix));
}


// GET SET
int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits" << std::endl;
	this->_raw = raw;
}


// CONSTRUCTOR DESTRUCTOR
Fixed::Fixed(void) : _raw(0)
{
	std::cout << " Fixed Default Constructor " << std::endl;
	return;
}

Fixed::Fixed(int i_param) : _raw(roundf((1 << _fix) * i_param))
{
	std::cout << " Fixed Int Constructor " << std::endl;
	return;
}

Fixed::Fixed(float f_param) : _raw(roundf((1 << _fix) * f_param))
{
	std::cout << " Fixed Float Constructor " << std::endl;
	return;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << " Fixed Copy Constructor " << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << " Fixed Destructor " << std::endl;
	return;
}


// ASSIGNATION OPERATOR
Fixed &	Fixed::operator=(Fixed const &rhs)
{
	std::cout << " Fixed Assignement Operator " << std::endl;

	if (this != &rhs)
		this->_raw = rhs.getRawBits();

	return *this;
}


std::ostream&	operator<<(std::ostream& o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
