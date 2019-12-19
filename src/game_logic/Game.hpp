/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:53:59 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/12/07 17:22:41 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_GAME_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_GAME_HPP

# include "Snake.hpp"
# include "Map.hpp"
# include <cstddef>
# include <memory>
# include <string>
# include <iostream>
# include "../other/DyLibLoad.hpp"
# include "../graphic/IGraphicLibrary.hpp"
# include "../sound/ISoundLib.hpp"

class IGraphicLibrary;

class	Game {
public:
	Game( int w, int h, const std::string & start_lib, const std::string & start_sound_lib);
	Game( const Game & ) = delete ;
	Game&	operator=( const Game & ) = delete ;
	~Game();

	void		start();
	void		startMenu();
	void		pauseMenu();
	void		controls();

private:
    enum {DEATH_MESSAGE_TIME = 5000};


    int     moveSnake();

	std::unique_ptr< Snake >				python_;
	std::unique_ptr< Snake >				cobra_;
	std::unique_ptr< MapStuff::Map >		map_;
	IGraphicLibrary*						glib_;
	ISoundLib*								slib_;
	bool	exit;
};

#endif