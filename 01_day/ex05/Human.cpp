/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:17:10 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/09 11:40:36 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"


std::string	Human::identify(void) const
{
	return (this->_brain.identify());
}

Brain	&Human::getBrain(void) const
{
	return ((Brain &)this->_brain);
}

Human::Human(void)
{
	std::cout << " Constructor Human " << std::endl;
	return;
}

Human::~Human(void)
{
	std::cout << " Desctructor Human " << std::endl;
	return;
}
