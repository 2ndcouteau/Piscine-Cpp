/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:01:54 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/10 17:27:24 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fix = 8;

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits" << std::endl;
	this->_raw = raw;
}


Fixed::Fixed(void) : _raw(0)
{
	std::cout << " Fixed Default Constructor " << std::endl;
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

Fixed &	Fixed::operator=(Fixed const &rhs)
{
	std::cout << " Fixed Assignement Operator " << std::endl;

	if (this != &rhs)
		this->_raw = rhs.getRawBits();

	return *this;
}
