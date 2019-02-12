/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GAME_H
# define __GAME_H

#include <time.h>
#include <ncurses.h>

#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>

#define GAME_H (50)
#define GAME_W (80)

class Game {
public:
	enum Type {
		GOOD,
		BAD
	};

	class Entity
	{
	public:
		int x;
		int y;
		Type type;
		Entity *next;
		uint64_t frame;
		bool kill;

	public:
		Entity(int x, int y, Type type);

		Entity();
		Entity(Entity const &src);
		virtual ~Entity();

		Entity &operator=(Entity const &rhs);
	};

	WINDOW *_info;
	int64_t count;

private:
	Entity *_map[GAME_W][GAME_H];
	uint64_t _frame;
	WINDOW *_window;


public:
	Game();
	virtual ~Game();

	int run();

	void push(Entity *entity);
	void pop(Entity *entity);
	void move(Entity *entity, int nx, int ny);
	Entity *get(int x, int y);

	uint64_t get_frame() const;
	WINDOW *get_window() const;
};

#endif /* !__GAME_H */
