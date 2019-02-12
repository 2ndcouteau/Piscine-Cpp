/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.cc                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:36:33 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 19:04:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <control.h>

#include "control.h"

Control::Control()
{
//	std::cout << " Control Default Constructor " << std::endl;
	return;
}

Control::Control(Control const &src)
{
//	std::cout << " Control Copy Constructor " << std::endl;
	*this = src;
	return;
}

Control::~Control()
{
//	std::cout << " Control Destructor " << std::endl;
	return;
}

Control &	Control::operator=(Control const &)
{
//	std::cout << " Control Assignement Operator " << std::endl;

	return *this;
}

void Control::control(Game &, int) { }
