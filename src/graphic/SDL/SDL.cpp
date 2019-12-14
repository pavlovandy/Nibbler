/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:23:30 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/20 18:42:12 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SDL.hpp"

SDL::SDL( int w, int h ) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0 || TTF_Init() == -1)
		throw std::runtime_error(SDL_GetError());
	if (!(win_ = SDL_CreateWindow("Nibbler SDL", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, w * SQUARE_SIZE, h * SQUARE_SIZE, SDL_WINDOW_SHOWN)))
		throw std::runtime_error(SDL_GetError());
	if (!(win_surr_ = SDL_GetWindowSurface(win_)))
		throw std::runtime_error(SDL_GetError());
	if (!(renderer_ = SDL_CreateRenderer(win_, -1, 0)))
		throw std::runtime_error(SDL_GetError());
	if (!(texture_menu_ = SDL_CreateTextureFromSurface(renderer_, IMG_Load("./resorces/texture/background.png"))))
		throw std::runtime_error(SDL_GetError());
}

SDL::~SDL() {
	SDL_FreeSurface(win_surr_);
	win_surr_ = nullptr;
	SDL_DestroyWindow(win_);
	win_ = nullptr;
	SDL_Quit();
}

void	SDL::displaySnake( const Snake & snake ) {
	std::vector< Dot<> >::const_iterator part = snake.getSnake().begin();
	displayRect(part->x * SQUARE_SIZE, part->y * SQUARE_SIZE, HEAD_COLOR, SQUARE_SIZE, SQUARE_SIZE);
	part++;
	for ( ; part != snake.getSnake().end(); part++) {
		displayRect(part->x * SQUARE_SIZE, part->y * SQUARE_SIZE, BODY_COLOR, SQUARE_SIZE, SQUARE_SIZE);
	}
}

void	SDL::displayRect( int x, int y, Uint32 c, int w, int h ) {
	SDL_Rect rec{x, y, w, h};
	SDL_FillRect(win_surr_, &rec, c);
}

void	SDL::update() {
	SDL_UpdateWindowSurface(win_);
}

void	SDL::displayMap( const MapStuff::Map & map ) {
	
	displayRect(0, 0, BACKGROUND_COLOR, map.getWidth() * SQUARE_SIZE, map.getHeight() * SQUARE_SIZE);
	
	for (auto & food : map.getCookies()) {
		displayRect(food.x * SQUARE_SIZE, food.y * SQUARE_SIZE, FOOD_COLOR, SQUARE_SIZE, SQUARE_SIZE);
	}
	for (auto & wall : map.getWall()) {
		displayRect(wall.x * SQUARE_SIZE, wall.y * SQUARE_SIZE, WALL_COLOR, SQUARE_SIZE, SQUARE_SIZE);
	}
}

void	SDL::delay( int64_t ms ) {
	SDL_Delay(ms);
}

ControlEvents	SDL::getNextEventInQueue( ) {
	if (SDL_PollEvent(&ev_)) {
		switch (ev_.type)
		{
			case SDL_KEYDOWN:
				switch (ev_.key.keysym.sym)
				{
					case SDLK_ESCAPE: return Quit;
					case SDLK_1: return Num1;
					case SDLK_2: return Num2;
					case SDLK_3: return Num3;
					case SDLK_SPACE: return StartSprint;
					case SDLK_w: return W;
					case SDLK_s: return S;
					case SDLK_a: return A;
					case SDLK_d: return D;
					case SDLK_LEFT: return Left;
					case SDLK_RIGHT: return Right;
					case SDLK_UP: return Up;
					case SDLK_p: return Pause;
					case SDLK_DOWN: return Down;
					case SDLK_RETURN : return Enter;
					default: return UnTrackedEvent;
				}
			case SDL_KEYUP:
				switch (ev_.key.keysym.sym)
				{
					case SDLK_SPACE: return StopSprint; break;
					default: return UnTrackedEvent; break;
				}
				break;
			default: return UnTrackedEvent; break;
		}
	}
	else
		return NoEvent;
}

extern "C" {
	IGraphicLibrary*	allocator( int w, int h) {
		return new SDL(w, h);
	}

	void				deallocator( IGraphicLibrary* glib ) {
		delete glib;
	}
}

void    SDL::displayScore( int x, int y, std::string text ) {
    static_cast<void>(x);
    static_cast<void>(y);
    static std::string prev(SDL_GetWindowTitle(win_));
    SDL_SetWindowTitle(win_, (prev + " | Score: " + text).c_str());
}
