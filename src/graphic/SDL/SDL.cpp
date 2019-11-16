/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:23:30 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/16 17:09:02 by Andrii Pavl      ###   ########.fr       */
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
}

void	SDL::close() {
	SDL_FreeSurface(win_surr_);
	SDL_DestroyWindow(win_);
	SDL_Quit();
}

SDL::~SDL() {
	close();
}

void	SDL::displaySnake( const Snake & snake ) {
	
}

void	SDL::displayMap( const Map & map ) {

}

ControlEvents	SDL::checkControls( Game & game ) {

}
