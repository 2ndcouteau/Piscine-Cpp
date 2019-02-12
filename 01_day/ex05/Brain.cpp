/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:17:07 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/09 11:01:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>
#include <cctype>

static std::string	upperaddr(std::string str)
{
	std::locale loc;

	for (size_t i = 2; i < str.length(); ++i)
		str[i] = toupper(str[i], loc);

	return (str);
}

std::string	Brain::identify(void) const
{
	std::ostringstream	address;

	address << (void const *)this;

	return(upperaddr(address.str()));
}

Brain::Brain(void)
{
	std::cout << " Constructor Brain " << std::endl;
	return;
}

Brain::~Brain(void)
{
	std::cout << " Destructor Brain " << std::endl;
	return;
}
