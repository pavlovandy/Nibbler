/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:53:22 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/16 17:08:28 by Andrii Pavl      ###   ########.fr       */
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
	ControlEvents	checkControls( Game & ) override ;
	void	close( ) override ;

private:
	SDL_Window*		win_;
	SDL_Surface*	win_surr_;
};

#endif