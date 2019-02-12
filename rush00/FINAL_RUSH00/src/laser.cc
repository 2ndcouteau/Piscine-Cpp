/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laser.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:34:36 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 19:20:19 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "laser.h"

Laser::Laser()
{
	return;
}

Laser::Laser(Laser const &src)
{
	*this = src;
	return;
}

Laser::~Laser()
{
}

Laser &	Laser::operator=(Laser const &rhs)
{
	if (this != &rhs) {
		this->_color = rhs.getColor();
		this->_visual = rhs.getVisual();

	}
	return *this;
}

Laser::Laser(int x, int y, Game::Type type, char const *visual, int color,
			 uint64_t speed) : Entity(x, y, type),
							   Collide(1),
							   Move(speed, Move::Up),
							   Render(type == Game::GOOD ? PLAYER : ENEMY),
							   _visual(visual), _color(color) {

	if (type == Game::BAD)
		Move::_direction = Down;
}

void Laser::render(Game &game) {
	wattron(game.get_window(), COLOR_PAIR(_color));
	mvwprintw(game.get_window(), y, x, _visual);
	wattroff(game.get_window(), COLOR_PAIR(_color));
}

char const *Laser::getVisual() const
{
	return (this->_visual);
}

int	Laser::getColor() const
{
	return (this->_color);
}
