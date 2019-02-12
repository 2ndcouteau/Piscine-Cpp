/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.cc                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:44:57 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 19:14:14 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <render.h>

#include "render.h"

Render::Render()
{
//	std::cout << " Render Default Constructor " << std::endl;
	return;
}

Render::Render(Render const &src)
{
//	std::cout << " Render Copy Constructor " << std::endl;
	*this = src;
	return;
}

Render::~Render()
{
//	std::cout << " Render Destructor " << std::endl;
	return;
}

Render &	Render::operator=(Render const &rhs)
{

	if (this != &rhs)
		this->_priority = rhs.get_priority();

	return *this;
}

void Render::render(Game &) {

}

Render::Render(Render::Priority _priority) : _priority(_priority) { }

Render::Priority Render::get_priority() const {
	return _priority;
}
