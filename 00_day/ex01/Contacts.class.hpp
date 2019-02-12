/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:55:39 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 15:37:07 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_CLASS_HPP
# define CONTACTS_CLASS_HPP

#include <iostream>

class Contacts
{

	public:
		Contacts(void);
		~Contacts(void);

		std::string infos[11];

		void		set_new_contact(Contacts *Contact);
		static void	print_contacts(Contacts *Contact, size_t nb_contact);
		static void	print_contact_info(Contacts *Contact, size_t nb_contact);
};

#endif
