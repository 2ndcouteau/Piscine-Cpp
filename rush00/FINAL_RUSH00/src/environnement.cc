/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement.cc                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:24:13 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 19:20:49 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environnement.h"

Environnement::Environnement(int x, int y)
 : Entity(x, y, Game::GOOD), Move(120, Down), Render(Render::ENV)
{
//	std::cout << " Environnement Default Constructor " << std::endl;
	return;
}

Environnement::Environnement(Environnement const &src)
{
//	std::cout << " Environnement Copy Constructor " << std::endl;
	*this = src;
	return;
}

Environnement::~Environnement(void)
{
//	std::cout << " Environnement Destructor " << std::endl;
	return;
}

Environnement &	Environnement::operator=(Environnement const &)
{
	return *this;
}

void Environnement::render(Game &game) {
	wattron(game.get_window(), COLOR_PAIR(5));
	mvwprintw(game.get_window(), y, x, "*");
	wattroff(game.get_window(), COLOR_PAIR(5));
}
