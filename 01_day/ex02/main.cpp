/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:41:49 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 20:22:40 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int main(void)
{
	Zombie Zombie("Big Boss Jacques");

	ZombieEvent	New_event;

	for (int i = 0 ; i < 20; i++)
		New_event.randomChump();
	return(0);
}
