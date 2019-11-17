/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:53:59 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/17 02:14:52 by anri             ###   ########.fr       */
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
	Game( size_t w, size_t h );
	Game( const Game & ) = delete ;
	Game&	operator=( const Game & ) = delete ;
	~Game() = default ;

	void		start();

private:
	bool		setEverythingUp();

	std::unique_ptr< Snake >	snake_;
	std::unique_ptr< MapStuff::Map >		map_;
	std::unique_ptr< IGraphicLibrary >	glib_;
};

#endif