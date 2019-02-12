/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:41:58 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 21:10:04 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce() const
{
	std::cout	<< "<" << this->name\
	 			<< " (" << this->type << ")>"\
				<< " Braiiiiiiinnnssss..."\
				<< std::endl;
}

Zombie::Zombie(void)
{
	std::cout << " A New Zombie has been created " << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << " A Zombie has been send in Hell " << std::endl;
	return;
}
