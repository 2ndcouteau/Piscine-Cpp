/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.cc                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:34:36 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 18:58:12 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collide.h>
#include <cassert>
#include <enemy.h>
#include <laser.h>

#include "collide.h"

size_t score = 0;

Collide::Collide()
{
//	std::cout << " Collide Default Constructor " << std::endl;
	return;
}

Collide::Collide(Collide const &src)
{
//	std::cout << " Collide Copy Constructor " << std::endl;
	*this = src;
	return;
}

Collide::~Collide()
{
//	std::cout << " Collide Destructor " << std::endl;
	return;
}

Collide &	Collide::operator=(Collide const &rhs)
{
//	std::cout << " Collide Assignement Operator " << std::endl;

	if (this != &rhs)
		this->_hp = rhs.get_hp();

	return *this;
}

Collide::Collide(size_t hp) : _hp(hp) { }

void Collide::collide(Game &game) {
	Game::Entity *a = dynamic_cast<Game::Entity *>(this);

	for (Game::Entity *b = game.get(a->x, a->y); b; b = b->next)
		if (!a->kill && !b->kill && b != a && b->type != a->type)
			if (Collide *cl = dynamic_cast<Collide *>(b)) {
				_hp -= 1;
				if (_hp == 0) {
					a->kill = true;
					if ((a->type == Game::BAD && b->type == Game::GOOD) &&
						dynamic_cast<Laser *>(b)) {
						if (dynamic_cast<Enemy *>(a))
							score += 5;
						else
							score += 1;
					}
					else if ((b->type == Game::BAD && a->type == Game::GOOD) &&
						dynamic_cast<Laser *>(a)) {
						if (dynamic_cast<Enemy *>(b))
							score += 5;
						else
							score += 1;
					}
				}
				cl->_hp -= 1;
				if (cl->_hp == 0) {
					dynamic_cast<Game::Entity *>(cl)->kill = true;
					if ((a->type == Game::BAD && b->type == Game::GOOD) &&
						dynamic_cast<Laser *>(b)) {
						if (dynamic_cast<Enemy *>(a))
							score += 5;
						else
							score += 1;
					}
					else if ((b->type == Game::BAD && a->type == Game::GOOD) &&
						dynamic_cast<Laser *>(a)) {
						if (dynamic_cast<Enemy *>(b))
							score += 5;
						else
							score += 1;
					}
				}
			}
}

size_t Collide::get_hp() const {
	return _hp;
}
