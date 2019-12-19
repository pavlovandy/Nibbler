/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:50:17 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/12/19 14:40:50 by Andrii Pavl      ###   ########.fr       */
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
	bool	flag_cobra = false; //to allow only change once direction per frame
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
			case Left:
				if (!flag_cobra && cobra_->lenght())
					cobra_->changeDir(Dot<>{-1, 0});
				flag_cobra = true;
				break;
			case Right:
				if (!flag_cobra && cobra_->lenght())
					cobra_->changeDir(Dot<>{1, 0});
				flag_cobra = true;
				break;
			case Up:
				if (!flag_cobra && cobra_->lenght())
					cobra_->changeDir(Dot<>{0, -1});
				flag_cobra = true;
				break;
			case Down:
				if (!flag_cobra && cobra_->lenght())
					cobra_->changeDir(Dot<>{0, 1});
				flag_cobra = true;
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

int		Game::moveSnake(std::unique_ptr< Snake > & snake, std::unique_ptr< Snake > & another) {
	snake->move();
	if (another) {
		if ( (snake->collision(another->getSnake()) != another->lenght()) ) {
			slib_->playSadSound();
			glib_->delay(DEATH_MESSAGE_TIME);
			return (true);
		}
	}
	if (snake->selfCollision() || snake->collision(map_->getWall()) != map_->getWall().size()) {
        slib_->playSadSound();
	    glib_->delay(DEATH_MESSAGE_TIME);
        return (true);
	}
	
	size_t num = snake->collision(map_->getCookies());
	if (num != map_->getCookies().size()) {
		snake->growUp();
        slib_->playHappySound();
		map_->getCookies()[num] = MapStuff::spawnFood( snake->getSnake(), *map_ );
	}
	return (false);
}
void		Game::startOne() {
	exit = false;
	
	while (!exit) {
		glib_->delay(80 - python_->lenght());
		controls();
		if (exit) return ;
		exit = moveSnake(python_, cobra_);
		if (!exit && python_->getSprintStatus())
			exit = moveSnake(python_, cobra_);
		if (exit) return ;
		glib_->displayMap(*map_);
		glib_->displaySnake(*python_);
		glib_->displayScore(map_->getWidth() / 2, 0, std::to_string(python_->lenght() - 4));
		glib_->update();
	}
}

void		Game::startTwo() {
	exit = false;
	
	while (!exit) {
		std::cout << std::max(python_->lenght(), cobra_->lenght()) << std::endl;
		glib_->delay(80 - std::max(python_->lenght(), cobra_->lenght()));
		controls();
		if (exit) return ;
		exit = moveSnake(python_, cobra_);
		if (exit) return ;
		exit = moveSnake(cobra_, python_);
		if (exit) return ;
		glib_->displayMap(*map_);
		glib_->displaySnake(*python_);
		glib_->displaySnake(*cobra_);
		//glib_->displayScore(map_->getWidth() / 2, 0, std::to_string(python_->lenght() + cobra_->lenght() - 8));
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
				if (gameMode == SinglePlayer)
					Game::startOne();
				else if (gameMode == MultiPlayer)
				{
					cobra_ = std::make_unique<Snake>(python_->getSnake()[0] + Dot<>{0, 4}, SnakeBodyColor::Color::BLUE, SnakeBodyColor::Color::CYAN);
					Game::startTwo();
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
