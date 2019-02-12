/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:42:07 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 20:49:00 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "ZombieEvent.hpp"

void	ZombieEvent::setZombieType(Zombie *zombie, size_t type)
{
	zombie->type = type;
	return;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie	*new_Zombie = new Zombie;

	new_Zombie->name = name;
	setZombieType(new_Zombie, ((rand() % 5) + 1));

	return (new_Zombie);
}

void	ZombieEvent::randomChump()
{
	std::string names[10] = {"Brigitte", "Jacques", "Bernard", "Pierre", "Paul",
							"Jacques", "Marlene", "Rachida", "Simone", "Marie"};

	Zombie	*current_zombie = newZombie(names[rand() % 10]);

	current_zombie->announce();

	delete current_zombie;
	current_zombie = NULL;
}


ZombieEvent::ZombieEvent(void)
{
	return;
}

ZombieEvent::~ZombieEvent(void)
{
	return;
}
