/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
//   Updated: 2019/01/13 20:13:13 by qrosa            ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <laser.h>

#include "game.h"
#include "player.h"
#include "collide.h"
#include "control.h"
#include "environnement.h"
#include "move.h"
#include "render.h"
#include "spawn.h"
#include "enemy.h"

Game::Entity::Entity() : x(), y(), type(), next(), frame(), kill() { }

Game::Entity::Entity(const Game::Entity &src)
	: x(), y(), type(), next(), frame(), kill() {
	*this = src;
}

Game::Entity::~Entity() { }

Game::Entity &Game::Entity::operator=(const Game::Entity &rhs) {
	this->x = rhs.x;
	this->y = rhs.y;
	this->type = rhs.type;
	this->next = rhs.next;
	this->frame = rhs.frame;
	return *this;
}

Game::Entity::Entity(int x, int y, Game::Type type)
	: x(x), y(y), type(type), next(nullptr), frame(0), kill(false) { }

Game::Game() :  count(0), _map(), _frame(0) {

	/* Init term with no delay, no cursor and keypad active */
	initscr();
	nodelay(stdscr, true);
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(false);

	/* Add dome pretty colors */
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);

	/* Main window creation.. */
	_window = newwin(GAME_H, GAME_W, 0, 0);
	_info = newwin(3, GAME_W, GAME_H, 0);
}

Game::~Game() {

	for (int y = 1; y < GAME_H - 1; ++y) {
		for (int x = 1; x < GAME_W - 1; ++x) {
			for (Entity *e = _map[x][y], *next; e; e = next) {
				next = e->next;
				delete e;
			}
		}
	}

	/* Delete game window then tell ncurses to reset term */
	delwin(_window);
	endwin();
}

static uint64_t bad_amount = 0;
static uint64_t bad_limit = 10;

int Game::run() {
	Player *player = new Player(GAME_W / 2, GAME_H - 5, 10);
	push(player);

	for (int i = 0; i < 9; ++i)
		push(new Environnement((rand() % GAME_W), (rand() % GAME_H)));

	for (int input; (input = getch()) != 27;) {

		/* Stop game loop */
		if (input == 'q' || input == KEY_EXIT) break;

		/* Yay, 60 fps */
		++this->_frame;
		std::chrono::steady_clock::time_point end =
			std::chrono::steady_clock::now() +
			std::chrono::milliseconds(8);

		werase(_window);
		mvwprintw(_info, 1, 1, "HP: %llu | ", player->get_hp());

		if ((_frame % 55) == 0)
			push(new Enemy((rand() % GAME_W), 1, 1));
		if ((_frame % 80) == 0)
			push(new Environnement((rand() % GAME_W), 1));
		if ((_frame % 3000) == 0) {
			push(new Laser((GAME_W / 2) - 3, 3, BAD, "(", 6, 40));
			push(new Laser((GAME_W / 2) - 2, 3, BAD, "/", 6, 40));
			push(new Laser((GAME_W / 2) - 1, 3, BAD, "'", 6, 40));
			push(new Laser((GAME_W / 2)    , 3, BAD, "o", 6, 40));
			push(new Laser((GAME_W / 2) + 1, 3, BAD, "'", 6, 40));
			push(new Laser((GAME_W / 2) + 2, 3, BAD, ")", 6, 40));
			push(new Laser((GAME_W / 2) + 3, 3, BAD, "/", 6, 40));
			push(new Laser((GAME_W / 2) + 3, 3, BAD, "/", 6, 40));
		}

		for (int y = 1; y < GAME_H - 1; ++y) {
			for (int x = 1; x < GAME_W - 1; ++x) {

				for (Entity *e = _map[x][y], *next; e; e = next) {
					next = e->next;

					/* Avoid to re-update game entity */
					if (e->frame == _frame) continue;
					e->frame = _frame;

					if (Control *c = dynamic_cast<Control *>(e))
						if (input > 0) c->control(*this, input);

					if (Move *m = dynamic_cast<Move *>(e))
						m->move(*this);

					if (e->kill) {
						if (e == player) {
							mvwprintw(_info, 1, 1,
									  "YOU DIED ! SCORE: %llu "
									  "(Press any key to quit)",
									  score);
							box(_info, ACS_VLINE, ACS_HLINE);
							wrefresh(_info);

							nodelay(stdscr, false);
							input = getch();
							(void)input;

							return 0;
						}

						pop(e);
						continue;
					}

					if (Spawn *s = dynamic_cast<Spawn *>(e))
						s->spawn(*this);

					if (Render *c = dynamic_cast<Render *>(e))
						c->render(*this);
				}
			}
		}

		wprintw(_info, "SCORE: %llu", score);

		box(_info, ACS_VLINE, ACS_HLINE);
		wrefresh(_info);

		box(_window, ACS_VLINE, ACS_HLINE);
		wrefresh(_window);

		std::this_thread::sleep_until(end);
	}

	return 0;
}

void Game::push(Entity *entity) {
	int x = entity->x, y = entity->y;

	if (!(x < GAME_W && y < GAME_H && x >= 0 && y >= 0) ||
		(dynamic_cast<Enemy *>(entity) &&
		bad_amount >= bad_limit)) {
		delete entity;
		return;
	}

	if (dynamic_cast<Enemy *>(entity))
		++bad_amount;

	Entity **it;

	if (Render *r = dynamic_cast<Render *>(entity)) {
		for (it = &_map[x][y]; *it; it = &(*it)->next)
			if (Render *rit = dynamic_cast<Render *>(*it))
				if (r->get_priority() > (*rit).get_priority())
					break;
	} else it = &_map[x][y];

	entity->next = *it;
	*it = entity;

	++count;
}

void Game::move(Entity *entity, int nx, int ny)
{
	int x = entity->x, y = entity->y;

	/* validate user input */
	if (nx >= GAME_W - 1 || ny >= GAME_H - 1 || nx <= 0 || ny <= 0)
		return (entity->kill = true), (void)0;

	assert(x < GAME_W && y < GAME_H && x >= 0 && y >= 0);

	/* Delete from linked list (previous position) */
	for (Entity **it = &_map[x][y]; *it; it = &(*it)->next)
		if (*it == entity) {
			*it = entity->next;
			--count;
			if (dynamic_cast<Enemy *>(entity))
				--bad_amount;
			break;
		}

	/* Insert at new position and set set new position */
	entity->x = nx;
	entity->y = ny;
	push(entity);

	if (Collide *cl = dynamic_cast<Collide *>(entity))
		cl->collide(*this);
}

void Game::pop(Entity *entity) {
	int x = entity->x, y = entity->y;

	assert(x < GAME_W && y < GAME_H && x >= 0 && y >= 0);

	for (Entity **it = &_map[x][y]; *it; it = &(*it)->next)
		if (*it == entity) {
			*it = entity->next;
			--count;
			if (dynamic_cast<Enemy *>(entity))
				--bad_amount;
			delete entity;
			return;
		}

	exit(1);
}

Game::Entity *Game::get(int x, int y) {
	if (x >= GAME_W || y >= GAME_H || x < 0 || y < 0)
		return NULL;
	return _map[x][y];
}

uint64_t Game::get_frame() const {
	return this->_frame;
}

WINDOW *Game::get_window() const {
	return _window;
}
