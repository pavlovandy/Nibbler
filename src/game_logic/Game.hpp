/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:53:59 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/09 16:48:18 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_GAME_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_GAME_HPP

# include "Snake.hpp"
# include "Map.hpp"
# include "../graphic/IGraphicLibrary.hpp"
# include <cstddef>

class	Game {
public:
	Game( size_t w, size_t h );
	Game( const Game & ) = delete;
	Game&	operator=( const Game & ) = delete;
	~Game();

	void		start();

private:
	bool		setEverythingUp();

	Snake	snake_; //or vector of snakes
	Map		map_;
	IGraphicLibrary*	glib_;
};

#endif