/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:53:22 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/20 16:45:24 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_GRAPHIC_SDL_HPP
# define NIBBLER_GRAPHIC_SDL_HPP

# include "../IGraphicLibrary.hpp"
# include <SDL2/SDL.h>

class SDL : public IGraphicLibrary {
public:
	SDL( int w, int h );
	SDL( SDL const & ) = delete ;
	SDL&	operator=( SDL const & ) = delete ;
	virtual ~SDL();
	
	void	displaySnake( const Snake & ) override ;
	void	displayMap( const MapStuff::Map & ) override ;
	ControlEvents	getNextEventInQueue( ) override ;
	void	update() override ;
	void	delay( size_t ms ) override ;

private:
	enum {	SQUARE_SIZE = 20 };
	enum {	BACKGROUND_COLOR = 0x7ec850, \
			HEAD_COLOR = 0x5A009D, \
			BODY_COLOR = 0x800080, \
			WALL_COLOR = 0x964B00, \
			FOOD_COLOR = 0xffff00 };

	void	displayRect( int x, int y, Uint32 c, int w, int h );

	SDL_Window*		win_;
	SDL_Surface*	win_surr_;
	SDL_Event		ev_;
};

#endif