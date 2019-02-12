/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:01:45 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/10 20:16:08 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;



	std::cout << "\nCustom Tests:\n" << std::endl;
	Fixed c(21.0f);
	Fixed d( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed zero(0);

	std::cout << "C = " << c << std::endl;
	std::cout << "D = " << d << std::endl;
	std::cout << "D left side" << std::endl;

	std::cout << "ADD:  " << d + c << std::endl;
	std::cout << "SUB:  " << d - c << std::endl;
	std::cout << "DIV:  " << d / c << std::endl;
	std::cout << "MUL:  " << d * c << std::endl;
	std::cout << "INF:  " << (d < c) << std::endl;
	std::cout << "SUP:  " << (d > c) << std::endl;
	std::cout << "INF=: " << (d <= c) << std::endl;
	std::cout << "SUP=: " << (d >= c) << std::endl;
	std::cout << "DIFF: " << (d != c) << std::endl;
	std::cout << "EQUA: " << (d == c) << std::endl;

	std::cout << "\nMultiplication and Division by 0" << std::endl;
	std::cout << "DIV0: " << (d / zero) << std::endl;
	std::cout << "MUL0: " << (d * zero) << std::endl;

	std::cout << "\nMin/Max" << std::endl;
	std::cout << "Max:  " << Fixed::max( c, d ) << std::endl;
	std::cout << "Min:  " <<Fixed::min( c, d ) << std::endl;

	return (0);
}
