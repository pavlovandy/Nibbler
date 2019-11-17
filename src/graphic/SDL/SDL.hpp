/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:53:22 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/17 00:26:44 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_GRAPHIC_SDL_HPP
# define NIBBLER_GRAPHIC_SDL_HPP

# include "../IGraphicLibrary.hpp"
# include <SDL2/SDL.h>

class SDL : public IGraphicLibrary {
public:
	enum { SQUARE_SIZE = 40 };

	SDL( int w, int h );
	SDL( SDL const & ) = delete ;
	SDL&	operator=( SDL const & ) = delete ;
	~SDL();
	
	void	displaySnake( const Snake & ) override ;
	void	displayMap( const Map & ) override ;
	ControlEvents	getNextEventInQueue( ) override ;

private:
	SDL_Window*		win_;
	SDL_Surface*	win_surr_;
	SDL_Event		ev;
};

#endif