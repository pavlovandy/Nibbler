/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:50:17 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/17 23:31:06 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "../other/DyLibLoad.hpp"
#include "Map.hpp"

Game::Game( int w, int h, const std::string & start_lib ) : glib_(nullptr), exit(false) {
	snake_ = std::make_unique<Snake>(Dot<>{w / 2, h / 2}); //set start snake
	map_ = std::make_unique< MapStuff::Map >(w, h); //make map
	map_->getCookies().push_back(MapStuff::spawnFood( snake_->getSnake(), *map_ )); // fill start food
	map_->getCookies().push_back(MapStuff::spawnFood( snake_->getSnake(), *map_ )); // fill start food
	glib_ = DyLibLoad::DyLibLoader::getInstance().loadLib(start_lib, w, h); // get graphic lib
}

void		Game::controls() {
	static auto & dlLoad = DyLibLoad::DyLibLoader::getInstance();
	for ( ControlEvents ev; (ev = glib_->getNextEventInQueue()) != NoEvent; ) {
		switch (ev){
			case Quit: exit = true; break;
			case Left: snake_.get()->changeDir(Dot<>{-1, 0}); break;
			case Right: snake_.get()->changeDir(Dot<>{1, 0}); break;
			case Up: snake_.get()->changeDir(Dot<>{0, -1}); break;
			case Down: snake_.get()->changeDir(Dot<>{0, 1}); break;
			case StartSprint: snake_.get()->sprintOn(); break;
			case StopSprint: snake_.get()->sprintOff(); break;
			case Num1:
				dlLoad.changeLib(SDL_LIB_PATH, map_.get()->getWidth(), map_.get()->getHeight());
			break;
			case Num2:
				dlLoad.changeLib(SFML_LIB_PATH, map_.get()->getWidth(), map_.get()->getHeight());
			break;
			case Num3:
				dlLoad.changeLib(OPENGL_LIB_PATH, map_.get()->getWidth(), map_.get()->getHeight());
			break;
			case UnTrackedEvent: break;
			default: break;
		}
	}
}

Game::~Game() {
	DyLibLoad::DyLibLoader::getInstance().closeLib();
}

void		Game::start() {
	exit = false;
	

	while (!exit) {
		glib_->displayMap( *map_ );
		glib_->displaySnake( *snake_ );
		glib_->update();
		glib_->delay(60);
		controls();
		snake_->move();
		if (snake_->selfColision() || snake_->obstacleColision(map_->getWall()))
			exit = true;
		size_t num = snake_->foodColison(map_->getCookies());
		if (num != map_->getCookies().size()) {
			map_->getCookies()[num] = MapStuff::spawnFood( snake_->getSnake(), *map_ );
		}
		if (snake_->getSprintStatus()) {
			snake_->move();
			if (snake_->selfColision() || snake_->obstacleColision(map_->getWall()))
				exit = true;
		}
	}
}
