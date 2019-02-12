/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:40:27 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/15 19:55:09 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctgmath>
#include <cfloat>

void	convert(char *argv1)
{
	char	_char;
	int		_int;
	float	_float;
	double	_double;

	std::string str = argv1;

	_double =	static_cast<double>(strtod(str.data(), NULL));
	_int =		static_cast<int>(_double);
	_float =	static_cast<float>(_double);
	_char =		static_cast<char>(_double);

	// Char Section
	if (_double >= 0 && _double <= 255)
	{
		if (isprint(_double))
			std::cout << "char: '" << _char << "'" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	// Int Section
	if (_double <= INT_MAX && _double >= INT_MIN)
		std::cout << "int: " << _int << std::endl;
	else
		std::cout << "int: impossible" << std::endl;


	// Float - Double Section
	std::cout.precision(1);
	std::cout << std::setiosflags(std::ios::fixed);
	std::cout << "float: " << _float << 'f' << std::endl;
	std::cout << "double: " << _double << std::endl;

}


int main(int argc, char **argv)
{
	if (argc == 2)
		convert(argv[1]);
	else
		std::cerr << "Usage: ./a.out ARG1" << std::endl;
	return (0);
}
