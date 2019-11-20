/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:58:12 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/20 15:50:21 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_MAP_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_MAP_HPP

# include <vector>
# include <cstddef>
# include "Dot.hpp"

namespace MapStuff {

	class Map {
	public:
		Map( int , int );
		~Map();
		int	getWidth() const ;
		int	getHeight() const ;
		std::vector< Dot<> >&	getCookies();
		const std::vector< Dot<> >&	getCookies() const ;
		const std::vector< Dot<> >&	getWall() const ;

	private:
		Map( const Map & );
		Map&	operator=( const Map & );

		int	width_;
		int	height_;
		std::vector< Dot<> >	cookies_;
		std::vector< Dot<> >	wall_;
	};

	void	createWallAtConstruct( int w, int h, std::vector< Dot<> >& wall);
	Dot<>	spawnFood( std::vector< Dot<> > snake, const MapStuff::Map & map );	
}

#endif