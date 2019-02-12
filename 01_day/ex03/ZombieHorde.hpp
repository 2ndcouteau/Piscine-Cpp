/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:22:39 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 21:44:09 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_CLASS_HPP
# define ZOMBIE_HORDE_CLASS_HPP

#include "Zombie.hpp"

class ZombieHorde
{

	public:
		ZombieHorde(int N);
		~ZombieHorde(void);

		Zombie	*GenHorde(int N);
		void	*KillHorde(Zombie *Horde);
		void	setZombieType(Zombie *zombie, size_t type);

		Zombie	*Horde;
};

#endif
