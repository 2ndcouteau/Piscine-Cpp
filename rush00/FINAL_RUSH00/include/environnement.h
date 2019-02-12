/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:24:09 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 19:28:00 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONNEMENT_CLASS_HPP
# define ENVIRONNEMENT_CLASS_HPP

#include "collide.h"
#include "move.h"
#include "spawn.h"
#include "render.h"

class Environnement : public Game::Entity,
	public Move, public Render
{
	public:
		Environnement(int x, int y);
		Environnement(Environnement const &src);
		virtual ~Environnement(void);

		Environnement &	operator=(Environnement const &);

	void render(Game &game);
};

#endif
