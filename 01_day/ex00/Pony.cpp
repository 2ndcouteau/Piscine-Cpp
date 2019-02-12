/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:02:56 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 20:35:10 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	Pony::ponyOnTheHeap(void)
{
	Pony	*Heapy = new Pony("Heapy");
	delete	Heapy;
	if (Heapy)
		std::cout	<< "Delete has been done BUT Heapy ptr is still availble, it's a miracle !!!\n"\
					<< "You should set it on NULL."\
					<< std::endl;
	Heapy = NULL;
	if (!Heapy)
		std::cout << "Ok now, Heapy is NULL !" << std::endl;
	return;
}

void	Pony::ponyOnTheStack(void)
{
	Pony	Stacky = Pony("Stacky");
	return;
}

Pony::Pony(std::string name) : _name(name)
{
	std::cout << "My Pretty Pony " << _name << " is Born !" << std::endl;
	return;
}

Pony::~Pony(void)
{
	std::cout << "My Dirty Pony " << _name << " has been DELETED ..." << std::endl;
	return;
}
