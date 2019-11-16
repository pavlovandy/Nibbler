/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphicLibrary.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:50:49 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/16 16:58:32 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GRAPHIC_IGRAPHICLIBRARY_HPP
# define NIBBLER_HEADERS_GRAPHIC_IGRAPHICLIBRARY_HPP

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
	virtual ControlEvents	checkControls( Game & ) = 0;
	virtual void	close() = 0;
};

#endif