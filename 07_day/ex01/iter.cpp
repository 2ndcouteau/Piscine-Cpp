/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:08:39 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/22 18:56:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

template < typename Array, typename Length, typename Type>
void iter(Array *array, Length length, Type func(Array&))
{
	Length i = 0;

	if (array != NULL)
	{
		while (i < length)
		{
			func(array[i]);
			i++;
		}
	}
}

template < typename toto >
void	add_one(toto &array)
{
	array += 1;
}

template <typename STR >
void	show_string(STR const & str)
{
	std::cout << str << std::endl;
}


int main(void)
{
	char str[11] = "abcdefghij";
	std::string days[6] = {"Bonjour", "Bonsoir", "Bom Dia", "Boa Tarde", "Boa Noite"};
	int tab[5] = {0, 1, 2, 3, 4};


	iter(tab, 5, show_string<int&>);
	//
	// std::cout << str << std::endl;
	// iter<char, int, void>(str, 7, add_one<char>);
	// std::cout << str << std::endl << std::endl;



	// iter<std::string, std::size_t, void>(days, sizeof(days)/sizeof(days[0]), show_string<std::string&>);

	return (0);
}
