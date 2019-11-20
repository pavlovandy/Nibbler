/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:53:59 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/20 21:08:49 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_GAME_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_GAME_HPP

# include "Snake.hpp"
# include "Map.hpp"
# include "../graphic/IGraphicLibrary.hpp"
# include <cstddef>
# include <memory>

class IGraphicLibrary;

class	Game {
public:
	Game( int w, int h, const std::string & start_lib = "src/libSFML.so" );
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