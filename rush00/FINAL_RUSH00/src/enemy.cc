/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:03:23 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 19:56:00 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <laser.h>
#include "enemy.h"

Enemy::Enemy()
{
//	std::cout << " Enemy Default Constructor " << std::endl;
	return;
}

Enemy::Enemy(Enemy const &src)
{
//	std::cout << " Enemy Copy Constructor " << std::endl;
	*this = src;
	return;
}

Enemy::~Enemy()
{
//	std::cout << " Enemy Destructor " << std::endl;
	return;
}

Enemy &	Enemy::operator=(Enemy const &)
{
//	std::cout << " Enemy Assignement Operator " << std::endl;
	return *this;
}

Enemy::Enemy(int x, int y, size_t hp)
	: Entity(x, y, Game::BAD), Collide(hp), Move(40, Down),
	  Spawn(30), Render(Render::ENEMY) { }

void Enemy::spawn(Game &game) {
	if ((rand() % 4) == 0 &&
		(game.get_frame() % Spawn::_frequency) == 0)
		game.push(new Laser(x, y + 1, Game::BAD, "T", 4, 5));
}

void Enemy::render(Game &game) {
	wattron(game.get_window(), COLOR_PAIR(1));
	mvwprintw(game.get_window(), y, x, "W");
	wattroff(game.get_window(), COLOR_PAIR(1));
}
