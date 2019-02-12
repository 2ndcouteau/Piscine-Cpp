/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:33:56 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 15:34:42 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
// #include <string.h>
#include <cstdlib>

#include <limits>		//

#include "Contacts.class.hpp"

const std::string commands[6] = {"ADD", "SEARCH", "EXIT", "add", "search", "exit"};

static int getcmd(std::string str)
{
	int i = 0;

	std::locale loc;

	while (i < (sizeof(commands) / sizeof(commands[0])))
	{
		if (!str.compare(commands[i]))
			return (i);
		i++;
	}
	return (-1);
}

static void	add_contact(Contacts *Contact)
{
	Contact->set_new_contact(Contact);
	return;
}

static void search_contact(Contacts *Contact, size_t nb_contact)
{
	if (nb_contact == 0)
	{
		std::cerr << "No Contact Available." << std::endl;
		return;
	}

	Contacts::print_contacts(Contact, nb_contact);

	Contacts::print_contact_info(Contact, nb_contact);
}

int main(void)
{
	Contacts	Contact[8];
	size_t		pos_contact = 0;
	size_t		nb_contact = 0;

	std::cout << "Welcome in PhoneBook !" << std::endl;
	while (42)
	{
		std::cout << "\nAvailable commands: ADD -- SEARCH -- EXIT\nEnter a command : ";

		std::string buff;
		std::cin >> buff;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		int cmd = getcmd(buff);
		switch (cmd % 3)
		{
			case 0: // ADD
				add_contact(&Contact[pos_contact]);
				pos_contact = (pos_contact < 7) ? pos_contact + 1 : 0;
				nb_contact = (nb_contact < 7) ? nb_contact + 1 : 8;
				break;
			case 1: // SEARCH
				search_contact(Contact, nb_contact);
				break;
			case 2: // EXIT
				return(0);
			default:
				std::cerr << "Command not available.\n";
		}
	} // End While(42)
	return (0);
}
