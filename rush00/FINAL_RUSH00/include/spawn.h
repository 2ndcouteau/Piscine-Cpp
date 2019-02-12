/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:45:33 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 19:15:52 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAWN_H
# define __SPAWN_H

#include "game.h"

class Spawn {
protected:
	uint64_t _frequency;

public:
	Spawn(uint64_t _frequency);

	Spawn();
	Spawn(Spawn const &src);
	virtual ~Spawn();

	Spawn &operator=(Spawn const &rhs);


	virtual void spawn(Game &);

	uint64_t	getFrequency(void) const;
};

#endif /* !__SPAWN_H */
