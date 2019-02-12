/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laser.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:03:06 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 19:19:46 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LASER_H
# define __LASER_H

#include "collide.h"
#include "move.h"
#include "render.h"

class Laser : public Game::Entity,
	public Collide, public Move, public Render {
private:
	char const *_visual;
	int _color;

public:
	Laser(int x, int y, Game::Type type, char const *visual, int color, uint64_t speed);

	Laser();
	Laser(Laser const &src);
	~Laser();

	Laser &operator=(Laser const &rhs);

	void render(Game &game);

	int	getColor() const;
	char const *getVisual() const;
};

#endif /* !__LASER_H */
