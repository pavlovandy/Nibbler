/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:48:09 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/20 15:54:43 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"
#include <random>
using MapStuff::Map;

void	MapStuff::createWallAtConstruct( int w, int h, std::vector< Dot<> >& wall ) {
	wall.clear();
	wall.reserve(static_cast<unsigned>(2 * (w + h) - 4));
	for (int y = 0; y < h; y++)
	{
		wall.push_back(Dot<>(0, y));
		wall.push_back(Dot<>(w - 1, y));
	}
	for (int x = 1; x < w - 1; x++) {
		wall.push_back(Dot<>(x, 0));
		wall.push_back(Dot<>(x, h - 1));
	}
}

Map::Map( int w , int h ) : width_(w), height_(h) {
	MapStuff::createWallAtConstruct(w, h, wall_); // fill the walls
	cookies_.reserve(4); // could be as much as we want
}

Map::~Map() {
	cookies_.clear();
	wall_.clear();
}

int	Map::getWidth() const {
	return width_;
}

int	Map::getHeight() const {
	return height_;	
}

std::vector< Dot<> >&	Map::getCookies() {
	return cookies_;
}

const std::vector< Dot<> >&	Map::getCookies() const {
	return cookies_;
}

const std::vector< Dot<> >&	Map::getWall() const {
	return wall_;
}

Dot<>	MapStuff::spawnFood( std::vector< Dot<> > snake, const MapStuff::Map & map ) {
	static std::default_random_engine generator{std::random_device()()};
	static std::uniform_int_distribution<int> scale_x(0, map.getWidth() - 1);
	static std::uniform_int_distribution<int> scale_y(0, map.getHeight() - 1);

	bool flag = false;
	Dot<>	res{0, 0};
	while (!flag) {
		flag = true;
		res = Dot<>(scale_x(generator), scale_y(generator));
		for ( auto& part : snake ) 
			if (part == res)
				flag = false;
		for ( auto& part : map.getWall() )
			if (part == res)
				flag = false;
		for ( auto& part : map.getCookies() )
			if (part == res)
				flag = false;
	}
	return (res);
}