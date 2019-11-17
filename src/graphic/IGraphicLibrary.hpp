/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphicLibrary.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:50:49 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/17 00:26:46 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GRAPHIC_IGRAPHICLIBRARY_HPP
# define NIBBLER_HEADERS_GRAPHIC_IGRAPHICLIBRARY_HPP

# include "../game_logic/Map.hpp"
# include "../game_logic/Snake.hpp"
# include "../game_logic/Game.hpp"

class Snake;
class Map;
class Game;

enum ControlEvents {
	Left,
	Right,
	Up,
	Down,
	Num1,
	Num2,
	Num3,
	Quit
};

class IGraphicLibrary {
public:
	virtual ~IGraphicLibrary() {}
	virtual	void	displaySnake( const Snake & ) = 0;
	virtual	void	displayMap( const Map & ) = 0;
	virtual ControlEvents	getNextEventInQueue( ) = 0;
};

#endif