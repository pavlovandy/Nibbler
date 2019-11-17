/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:58:12 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/11 16:53:16 by anri             ###   ########.fr       */
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
		Map( size_t , size_t );
		~Map();
		size_t	getWidth() const ;
		size_t	getHeight() const ;
		std::vector< Block >&	getCookies();
		const std::vector< Block >&	getWall() const ;

	private:
		Map( const Map & );
		Map&	operator=( const Map & );

		size_t	width_;
		size_t	height_;
		std::vector< Block >	cookies_;
		std::vector< Block >	wall_;
	};

	void	createWallAtConstruct( size_t w, size_t h, std::vector< Block >& wall);
}

#endif