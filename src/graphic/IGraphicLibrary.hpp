/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphicLibrary.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:50:49 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/17 21:58:43 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GRAPHIC_IGRAPHICLIBRARY_HPP
# define NIBBLER_HEADERS_GRAPHIC_IGRAPHICLIBRARY_HPP

# include "../game_logic/Game.hpp"

class Snake;
class Map;
class Game;

enum ControlEvents {
	NoEvent,
	UnTrackedEvent,
	Left,
	Right,
	Up,
	Down,
	StartSprint,
	StopSprint,
	Num1,
	Num2,
	Num3,
	Quit
};

class IGraphicLibrary {
public:
	virtual ~IGraphicLibrary() {}
	virtual	void	displaySnake( const Snake & ) = 0;
	virtual	void	displayMap( const MapStuff::Map & ) = 0;
	virtual ControlEvents	getNextEventInQueue( ) = 0;
	virtual	void	update() = 0;
	virtual void	delay( size_t ms ) = 0;
};

#endif