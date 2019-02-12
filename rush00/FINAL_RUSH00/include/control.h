/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:37:02 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 19:04:47 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTROL_H
# define __CONTROL_H

#include "game.h"

class Control {
public:
	Control();
	Control(Control const &src);
	~Control();

	Control &operator=(Control const &);

	virtual void control(Game &, int);
};

#endif /* !__CONTROL_H */
