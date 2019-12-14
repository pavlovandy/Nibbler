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

Game::Game( int w, int h,
        const std::string & start_lib,
        const std::string & start_sound_lib )
        : glib_(nullptr), slib_(nullptr), exit(false) {
	snake_ = std::make_unique<Snake>(Dot<>{w / 2, h / 2}); //set start snake
	map_ = std::make_unique< MapStuff::Map >(w, h); //make map
	map_->getCookies().push_back(MapStuff::spawnFood( snake_->getSnake(), *map_ )); // fill start food
	map_->getCookies().push_back(MapStuff::spawnFood( snake_->getSnake(), *map_ )); // fill start food


	glib_ = DyLibLoad::DyLibLoader<IGraphicLibrary>::getInstance().loadLib(start_lib, w, h);
	slib_ = DyLibLoad::DyLibLoader<ISoundLib>::getInstance().loadLib(start_sound_lib, 0, 0);
}

void		Game::controls() {
	static auto & dlLoad = DyLibLoad::DyLibLoader<IGraphicLibrary>::getInstance();
	bool	flag = false; //to allow only change once direction per frame
	for ( ControlEvents ev; (ev = glib_->getNextEventInQueue()) != NoEvent; ) {
		switch (ev){
			case Quit: exit = true; break;
			case Left: 
				if (!flag)
					snake_->changeDir(Dot<>{-1, 0});
				flag = true; 
				break;
			case Right:
				if (!flag)
					snake_->changeDir(Dot<>{1, 0});
				flag = true;
				break;
			case Up: 
				if (!flag)
					snake_->changeDir(Dot<>{0, -1});
				flag = true; 
				break;
			case Down: 
				if (!flag)
					snake_->changeDir(Dot<>{0, 1});
				flag = true;
				break;
			case StartSprint: if (!flag) snake_->sprintOn(); break;
			case StopSprint: if (!flag) snake_->sprintOff(); break;
			case Num1:
				glib_ = dlLoad.changeLib(SDL_LIB_PATH, map_->getWidth(), map_->getHeight());
			break;
			case Num2:
				glib_ = dlLoad.changeLib(SFML_LIB_PATH, map_->getWidth(), map_->getHeight());
			break;
			case Num3:
				glib_ = dlLoad.changeLib(OPENGL_LIB_PATH, map_->getWidth(), map_->getHeight());
			break;
			default: break;
		}
	}
}

Game::~Game() {
	DyLibLoad::DyLibLoader<IGraphicLibrary>::getInstance().closeLib();
    DyLibLoad::DyLibLoader<ISoundLib>::getInstance().closeLib();
}

int		Game::moveSnake() {
	snake_->move();
	if (snake_->selfCollision() || snake_->collision(map_->getWall()) != map_->getWall().size()) {
        slib_->playSadSound();
	    glib_->delay(DEATH_MESSAGE_TIME);
        return (true);
	}

	size_t num = snake_->collision(map_->getCookies());
	if (num != map_->getCookies().size()) {
		snake_->growUp();
        slib_->playHappySound();
		map_->getCookies()[num] = MapStuff::spawnFood( snake_->getSnake(), *map_ );
	}
	return (false);
}

void		Game::start() {
	exit = false;

	while (!exit) {
		glib_->delay(60 - snake_->lenght());
		controls();
		if (exit) return ;
		exit = moveSnake();
		if (!exit && snake_->getSprintStatus())
			exit = moveSnake();
		if (exit) return ;
		glib_->displayMap( *map_ );
		glib_->displaySnake( *snake_ );
		glib_->displayScore( map_->getWidth() / 2, 0, std::to_string(snake_->lenght()) );
		glib_->update();
	}
}
