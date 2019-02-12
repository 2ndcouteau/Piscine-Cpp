/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:01:54 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 15:09:21 by qrosa            ###   ########.fr       */
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
	// std::cout << " Fixed Default Constructor " << std::endl;
	return;
}

Fixed::Fixed(int i_param) : _raw(roundf((1 << _fix) * i_param))
{
	// std::cout << " Fixed Int Constructor " << std::endl;
	return;
}

Fixed::Fixed(float f_param) : _raw(roundf((1 << _fix) * f_param))
{
	// std::cout << " Fixed Float Constructor " << std::endl;
	return;
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << " Fixed Copy Constructor " << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	// std::cout << " Fixed Destructor " << std::endl;
	return;
}


// ASSIGNATION OPERATOR
Fixed &	Fixed::operator=(Fixed const &rhs)
{
	// std::cout << " Fixed Assignement Operator " << std::endl;

	if (this != &rhs)
		this->_raw = rhs.getRawBits();

	return *this;
}


std::ostream&	operator<<(std::ostream& o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}


// COMPARAISON OPERATORS
bool	Fixed::operator==(Fixed const &rhs)
{
	return (getRawBits() == rhs.getRawBits() ? true : false);
}

bool	Fixed::operator!=(Fixed const &rhs)
{
	return !operator==(rhs);
}

bool	Fixed::operator< (Fixed const &rhs)
{
	return (getRawBits() < rhs.getRawBits() ? true : false);
}

bool	Fixed::operator> (Fixed const &rhs)
{
	return  !operator< (rhs);
}

bool	Fixed::operator<=(Fixed const &rhs)
{
	return !operator> (rhs);
}

bool	Fixed::operator>=(Fixed const &rhs)
{
	return !operator< (rhs);
}


// OPERATIONS OPERATORS
Fixed	Fixed::operator+(Fixed const &rhs)
{
	return(Fixed(toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &rhs)
{
	return(Fixed(toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &rhs)
{
	if (rhs.getRawBits() == 0)
		return (Fixed(0));
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &rhs)
{
	if (rhs.getRawBits() == 0)
		return (Fixed(0));
	return(Fixed(toFloat() / rhs.toFloat()));
}

// INCREMENTATION OPERATORS
Fixed&	Fixed::operator++()
{
	++_raw;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed res;

	res.setRawBits(getRawBits());
	++_raw;
	return (res);
}

Fixed&	Fixed::operator--()
{
	--_raw;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed res;

	res.setRawBits(getRawBits());
	--_raw;
	return (res);
}


// MIN MAX OPERATORS
Fixed&			Fixed::min(Fixed const & f1, Fixed const & f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return ((Fixed&)f1);
	return ((Fixed&)f2);
}

Fixed&			Fixed::min(Fixed & f1, Fixed & f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed&			Fixed::max(Fixed const & f1, Fixed const & f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return ((Fixed&)f1);
	return ((Fixed&)f2);
}

Fixed&			Fixed::max(Fixed & f1, Fixed & f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}
