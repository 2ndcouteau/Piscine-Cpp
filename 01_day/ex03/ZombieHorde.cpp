/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:22:00 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 21:44:36 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

void	ZombieHorde::setZombieType(Zombie *zombie, size_t type)
{
	zombie->type = type;
	return;
}

void	*ZombieHorde::KillHorde(Zombie *Horde)
{
	delete [] Horde;
	Horde = NULL;

	return (NULL);
}

Zombie	*ZombieHorde::GenHorde(int N)
{
	std::string names[10] = {"Brigitte", "Jacques", "Bernard", "Pierre", "Paul",
	"Jacques", "Marlene", "Rachida", "Simone", "Marie"};

	Zombie	*new_Zombie = new Zombie[N];

	for (size_t i = 0; i < N; ++i)
	{
		new_Zombie[i].name = names[rand() % 10];
		setZombieType(&new_Zombie[i], ((rand() % 5) + 1));
		new_Zombie[i].announce();
	}
	return (new_Zombie);
}


ZombieHorde::ZombieHorde(int N)
{
	std::cout << "--- Constructor of the Horde ---\n" << std::endl;

	this->Horde = GenHorde(N);

	if (this->Horde)
		std::cout << "\nThe Horde Is Alive !\n" << std::endl;

	return;
}

ZombieHorde::~ZombieHorde(void)
{
	std::cout << "\n--- Horde Destructor ---\n" << std::endl;

	KillHorde(this->Horde);
	this->Horde = NULL;

	if (!this->Horde)
		std::cout << "\nThe Horde Has Been Killed !" << std::endl;

	return;
}
