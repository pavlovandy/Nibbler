/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:53:59 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/30 16:42:04 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_GAME_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_GAME_HPP

# include "Snake.hpp"
# include "Map.hpp"
# include "../graphic/IGraphicLibrary.hpp"
# include <cstddef>
# include <memory>
# include <string>
# include "../other/DyLibLoad.hpp"

class IGraphicLibrary;

class	Game {
public:
	Game( int w, int h, const std::string & start_lib = SDL_LIB_PATH);
	Game( const Game & ) = delete ;
	Game&	operator=( const Game & ) = delete ;
	~Game();

	void		start();
	void		controls();

private:
	bool		setEverythingUp();

	std::unique_ptr< Snake >		snake_;
	std::unique_ptr< MapStuff::Map >		map_;
	IGraphicLibrary*	glib_;
	bool	exit;
};

#endif