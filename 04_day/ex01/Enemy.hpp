/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:00:48 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/13 15:34:12 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include <iostream>

class Enemy : public Game::Entity,
	public Collide, public Move, public Render
{
	private:

	protected:
		Enemy(void);

	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const &src);
		virtual ~Enemy(void);

		virtual void takeDamage(int);

		virtual Enemy &	operator=(Enemy const &rhs);
};

std::ostream &	operator<<(std::ostream &o, Enemy const &rhs);

#endif
