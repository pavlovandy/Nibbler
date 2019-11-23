/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:50:17 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/23 18:55:10 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game( int w, int h, const std::string & start_lib ) : glib_(nullptr), exit(false) {
	snake_ = std::make_unique<Snake>(Dot<>{w / 2, h / 2}); //set start snake
	map_ = std::make_unique< MapStuff::Map >(w, h); //make map
	map_->getCookies().push_back(MapStuff::spawnFood( snake_->getSnake(), *map_ )); // fill start food
	map_->getCookies().push_back(MapStuff::spawnFood( snake_->getSnake(), *map_ )); // fill start food
	glib_ = DyLibLoad::DyLibLoader::getInstance().loadLib(start_lib, w, h); // get graphic lib
}

void		Game::controls() {
	static auto & dlLoad = DyLibLoad::DyLibLoader::getInstance();
	bool	flag = false; //to allow only change once directrion per frame
	for ( ControlEvents ev; (ev = glib_->getNextEventInQueue()) != NoEvent; ) {
		switch (ev){
			case Quit: exit = true; break;
			case Left: 
				if (!flag)
					snake_.get()->changeDir(Dot<>{-1, 0});
				flag = true; 
				break;
			case Right:
				if (!flag)
					snake_.get()->changeDir(Dot<>{1, 0});
				flag = true;
				break;
			case Up: 
				if (!flag)
					snake_.get()->changeDir(Dot<>{0, -1});
				flag = true; 
				break;
			case Down: 
				if (!flag)
					snake_.get()->changeDir(Dot<>{0, 1});
				flag = true;
				break;
			case StartSprint: if (!flag) snake_.get()->sprintOn(); break;
			case StopSprint: if (!flag) snake_.get()->sprintOff(); break;
			case Num1:
				glib_ = dlLoad.changeLib(SDL_LIB_PATH, map_.get()->getWidth(), map_.get()->getHeight());
			break;
			case Num2:
				glib_ = dlLoad.changeLib(SFML_LIB_PATH, map_.get()->getWidth(), map_.get()->getHeight());
			break;
			case Num3:
				glib_ = dlLoad.changeLib(OPENGL_LIB_PATH, map_.get()->getWidth(), map_.get()->getHeight());
			break;
			case UnTrackedEvent: break;
			default: break;
		}
	}
}

Game::~Game() {
	DyLibLoad::DyLibLoader::getInstance().closeLib();
}

static int		moveSnake( Snake* snake_, MapStuff::Map* map_ ) {
	snake_->move();
	if (snake_->selfCollision() || snake_->collision(map_->getWall()) != map_->getWall().size())
		return (true);
	size_t num = snake_->collision(map_->getCookies());
	if (num != map_->getCookies().size()) {
		snake_->growUp();
		map_->getCookies()[num] = MapStuff::spawnFood( snake_->getSnake(), *map_ );
	}
	return (false);
}

void		Game::start() {
	exit = false;
	while (!exit) {
		glib_->delay(60);
		controls();
		if (exit) return ;
		exit = moveSnake(snake_.get(), map_.get());
		if (!exit && snake_->getSprintStatus())
			exit = moveSnake(snake_.get(), map_.get());
		if (exit) return ;
		glib_->displayMap( *map_ );
		glib_->displaySnake( *snake_ );
		glib_->update();
	}
}
