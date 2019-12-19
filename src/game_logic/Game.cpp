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
	python_ = std::make_unique<Snake>(Dot<>{w / 2, h / 2}, SnakeBodyColor::Color::RED, SnakeBodyColor::Color::LIGHTRED); //set start snake
	map_ = std::make_unique< MapStuff::Map >(w, h); //make map
	map_->getCookies().push_back(MapStuff::spawnFood( python_->getSnake(), *map_ )); // fill start food
	map_->getCookies().push_back(MapStuff::spawnFood( python_->getSnake(), *map_ )); // fill start food
	
	glib_ = DyLibLoad::DyLibLoader<IGraphicLibrary>::getInstance().loadLib(start_lib, w, h);
	slib_ = DyLibLoad::DyLibLoader<ISoundLib>::getInstance().loadLib(start_sound_lib, 0, 0);
}

void		Game::controls() {
	static auto & dlLoad = DyLibLoad::DyLibLoader<IGraphicLibrary>::getInstance();
	bool	flag = false; //to allow only change once direction per frame
	for ( ControlEvents ev; (ev = glib_->getNextEventInQueue()) != NoEvent; ) {
		switch (ev){
			case Quit: exit = true; break;
			case A:
				if (!flag)
					python_->changeDir(Dot<>{-1, 0});
				flag = true; 
				break;
			case D:
				if (!flag)
					python_->changeDir(Dot<>{1, 0});
				flag = true;
				break;
			case W:
				if (!flag)
					python_->changeDir(Dot<>{0, -1});
				flag = true; 
				break;
			case S:
				if (!flag)
					python_->changeDir(Dot<>{0, 1});
				flag = true;
				break;
			case StartSprint: if (!flag) python_->sprintOn(); break;
			case StopSprint: if (!flag) python_->sprintOff(); break;
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
	python_->move();
	if (python_->selfCollision() || python_->collision(map_->getWall()) != map_->getWall().size()) {
        slib_->playSadSound();
	    glib_->delay(DEATH_MESSAGE_TIME);
        return (true);
	}

	size_t num = python_->collision(map_->getCookies());
	if (num != map_->getCookies().size()) {
		python_->growUp();
        slib_->playHappySound();
		map_->getCookies()[num] = MapStuff::spawnFood( python_->getSnake(), *map_ );
	}
	return (false);
}
void		Game::start() {
	exit = false;
	
	while (!exit) {
		glib_->delay(60 - python_->lenght());
		controls();
		if (exit) return ;
		exit = moveSnake();
		if (!exit && python_->getSprintStatus())
			exit = moveSnake();
		if (exit) return ;
		glib_->displayMap(*map_);
		glib_->displaySnake(*python_);
		glib_->displayScore(map_->getWidth() / 2, 0, std::to_string(python_->lenght() - 4));
		glib_->update();
	}
}

void Game::startMenu()
{
	GameMode gameMode = SinglePlayer;
	glib_->displayMenu(gameMode);
	for (ControlEvents ev; true; )
	{
		ev = glib_->getNextEventInQueue();
		switch (ev)
		{
			case Enter :
			{
				if (gameMode == SinglePlayer || gameMode == MultiPlayer)
				{
					if (gameMode == MultiPlayer)
						cobra_ = std::make_unique<Snake>(python_->getSnake()[0] - Dot<>{0, 4}, SnakeBodyColor::Color::BLUE, SnakeBodyColor::Color::CYAN);
					Game::start();
				}
				else
					return;
			}
			case Quit:
				return;
			case Up :
			{
				if (gameMode == SinglePlayer)
					gameMode = Exit;
				else if (gameMode == MultiPlayer)
					gameMode = SinglePlayer;
				else
					gameMode = MultiPlayer;
				break;
			}
			case Down :
			{
				if (gameMode == SinglePlayer)
					gameMode = MultiPlayer;
				else if (gameMode == MultiPlayer)
					gameMode = Exit;
				else
					gameMode = SinglePlayer;
				break;
			}
			default:
				break;
		}
		glib_->displayMenu(gameMode);
	}
}
