/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:58:12 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/09 16:23:07 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_MAP_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_MAP_HPP

# include <vector>
# include <cstddef>

class Map {
public:
	Map&	instance();
	bool	setSize( size_t , size_t );
	size_t	getWidth() const ;
	size_t	getHeight() const ;
	//mb there should be function for spawn food or other things

private:
	Map();
	~Map();
	Map( const Map & );
	Map&	operator=( const Map & );

	size_t	width_;
	size_t	height_;
	//IEntitry* entites for drawing:
	//all part of snake food blocks
};

#endif