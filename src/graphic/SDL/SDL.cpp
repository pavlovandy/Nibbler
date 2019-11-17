/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:23:30 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/17 02:48:49 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SDL.hpp"

SDL::SDL( int w, int h ) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		throw SDL_GetError();
	if (!(win_ = SDL_CreateWindow("Nibbler SDL", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN)))
		throw SDL_GetError();
	if (!(win_surr_ = SDL_GetWindowSurface(win_)))
		throw SDL_GetError();


	SDL_UpdateWindowSurface(win_);
}

SDL::~SDL() {
	SDL_FreeSurface(win_surr_);
	win_surr_ = nullptr;
	SDL_DestroyWindow(win_);
	win_ = nullptr;
	SDL_Quit();
}

void	SDL::displaySnake( const Snake & snake ) {
	
}

void	SDL::displayMap( const Map & map ) {

}

ControlEvents	SDL::getNextEventInQueue( ) {
	return Left;
}

extern "C" {
	IGraphicLibrary*	allocator( int w, int h) {
		return new SDL(w, h);
	}

	void				deallocator( IGraphicLibrary* glib ) {
		delete glib;
	}
}
