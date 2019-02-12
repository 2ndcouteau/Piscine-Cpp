/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cc                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:02:56 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 19:13:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "laser.h"

Player::Player()
{
//	std::cout << " Player Default Constructor " << std::endl;
	return;
}

Player::Player(Player const &src)
{
//	std::cout << " Player Copy Constructor " << std::endl;
	*this = src;
	return;
}

Player::~Player()
{
//	std::cout << " Player Destructor " << std::endl;
	return;
}

Player &	Player::operator=(Player const &)
{
	return *this;
}

Player::Player(int x, int y, size_t hp)
	: Entity(x, y, Game::GOOD), Collide(hp), Control(), Render(Render::PLAYER)
	{ }

void Player::control(Game &game, int input) {
	switch (input) {
	case KEY_LEFT:
		if (x > 1) game.move(this, x - 1, y);
		break;
	case KEY_RIGHT:
		if (x < GAME_W - 2) game.move(this, x + 1, y);
		break;
	case KEY_UP:
		if (y > 1) game.move(this, x, y - 1);
		break;
	case KEY_DOWN:
		if (y < GAME_H - 2) game.move(this, x, y + 1);
		break;
	case ' ':
		game.push(new Laser(x, y - 1, Game::GOOD, "\'", 3, 5));
		break;
	default:
		break;
	}
}

void Player::render(Game &game) {
	wattron(game.get_window(), COLOR_PAIR(2));
	mvwprintw(game.get_window(), y, x, "^");
	wattroff(game.get_window(), COLOR_PAIR(2));
}
