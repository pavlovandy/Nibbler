/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:58:12 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/17 23:31:51 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_MAP_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_MAP_HPP

# include <vector>
# include <cstddef>
# include "Block.hpp"

namespace MapStuff {

	class Map {
	public:
		Map( int , int );
		~Map();
		int	getWidth() const ;
		int	getHeight() const ;
		std::vector< Block >&	getCookies();
		const std::vector< Block >&	getCookies() const ;
		const std::vector< Block >&	getWall() const ;

	private:
		Map( const Map & );
		Map&	operator=( const Map & );

		int	width_;
		int	height_;
		std::vector< Block >	cookies_;
		std::vector< Block >	wall_;
	};

	void	createWallAtConstruct( int w, int h, std::vector< Block >& wall);
	Block	spawnFood( std::vector< Dot<> > snake, const MapStuff::Map & map );	
}

#endif