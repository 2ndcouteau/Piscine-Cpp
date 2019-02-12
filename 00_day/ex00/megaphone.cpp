/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:05:46 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 09:18:55 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	upperstring(std::string str)
{
	std::locale loc;

	for (size_t i = 0; i < str.length(); ++i)
		std::cout << std::toupper(str[i], loc);
}

int main(int argc, char **argv)
{
	int nb = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (nb < argc)
		{
			if (nb != 1)
				std::cout << " ";
			upperstring(argv[nb]);
			nb++;
		}
		std::cout << std::endl;
	}
	return (0);
}
