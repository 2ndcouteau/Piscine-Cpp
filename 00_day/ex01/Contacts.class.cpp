/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:09:55 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 15:35:25 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include <limits>		//

#include "Contacts.class.hpp"

std::string info_name[11] = { "first name", "last_name", "nickname", "login",
							"postal_address", "email_address", "phone_number",
							"birthday_date", "favorite_meal", "underwear_color",
							"darkest_secret"
						};

static void	ptrint_elem(std::string str)
{
	char	cpy[11];
	size_t	i = 0;
	size_t	len = str.length();

	if (len == 0)
		strcpy(cpy, "empty     ");
	else if (len > 10)
	{
		strncpy (cpy, str.c_str(), 9);
		cpy[9] = '.';
		cpy[10] = '\0';
	}
	else
	{
		strncpy (cpy, str.c_str(), str.length());
		while (len + i < 10)
		{
			cpy[len + i] = ' ';
			i++;
		}
		cpy[10] = '\0';
	}

	std::cout << cpy << "|";
}

void	Contacts::print_contact_info(Contacts *Contact, size_t nb_contact)
{
	size_t 		i = 0;
	size_t		i_index = 0;
	std::string	index;


	std::cout << "Choose a contact (Use number 1 to 8) : ";
	std::cin >> index;
	i_index = atoi(index.c_str());

	if ((i_index < 1 || i_index > 8) || (i_index > nb_contact))
	{
		std::cerr << "Bad index, please retry your search." << std::endl;
		return;
	}

	std::cout << "Your choosed the contact: " << i_index << std::endl << std::endl;
	while (i < 11)
	{
		std::cout << info_name[i] << ": " << Contact[i_index - 1].infos[i] << std::endl;
		i++;
	}
}

void	Contacts::print_contacts(Contacts *Contact, size_t nb_contact)
{
	size_t	i = 0;

	std::cout << "_____________________________________________\n\
|index     |first name|last name |nickname  |" << std::endl;

	while (i < 8 && i < nb_contact)
	{
		std::cout << "|" << i + 1 << "         |";
		ptrint_elem(Contact[i].infos[0]);
		ptrint_elem(Contact[i].infos[1]);
		ptrint_elem(Contact[i].infos[2]);
		std::cout << std::endl;
		i++;
	}
	std::cout << "|___________________________________________|\n";
}


static void	clean_contact_info(Contacts *Contact)
{
	size_t i = 0;

	while (i < 11)
	{
		Contact->infos[i].clear();
		i++;
	}
}

static void	get_infos(Contacts *Contact)
{
	size_t i = 0;

	while (i < 11)
	{
		std::cout << "Please enter the contact " << info_name[i] << " :" << std::endl;
		std::getline (std::cin, Contact->infos[i], '\n');
		i++;
	}
}

void	Contacts::set_new_contact(Contacts *Contact)
{
	clean_contact_info(Contact);
	get_infos(Contact);
}

Contacts::Contacts(void)
{
	return;
}

Contacts::~Contacts(void)
{
	return;
}
