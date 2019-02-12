/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:41:19 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 19:10:13 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MOVE_H
# define __MOVE_H

#include "game.h"

class Move {
public:
	enum Direction { Left, Right, Up, Down };

protected:
	uint64_t _frequency;
	Direction _direction;

public:
	Move(uint64_t frequency, Direction direction);

	Move();
	Move(Move const &src);
	~Move();

	Move &operator=(Move const &rhs);

	virtual void move(Game &);
	
	uint64_t		getFrequency(void) const;
	Direction 		getDirection(void) const;

};

#endif /* !__MOVE_H */
