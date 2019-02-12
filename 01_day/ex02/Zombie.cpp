/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:41:58 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 20:21:23 by qrosa            ###   ########.fr       */
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

Zombie::Zombie(std::string new_name) : name(new_name)
{
	std::cout << " The New Zombie " + new_name + " has been created " << std::endl;
	return;
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
