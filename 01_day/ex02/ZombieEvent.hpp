/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:42:14 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 20:01:49 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_CLASS_HPP
# define ZOMBIE_EVENT_CLASS_HPP

#include "Zombie.hpp"

class ZombieEvent
{

	public:
		ZombieEvent(void);
		~ZombieEvent(void);

		void	setZombieType(Zombie *zombie, size_t Type);
		Zombie* newZombie(std::string name);

		void	randomChump(void);
};

#endif
