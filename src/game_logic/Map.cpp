/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:48:09 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/11 17:31:13 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"

using MapStuff::Map;

void	MapStuff::createWallAtConstruct( size_t w, size_t h, std::vector< Block >& wall ) {
	wall.clear();
	wall.reserve(2 * (w + h) - 4);
	for (size_t y = 0; y < h; y++)
	{
		wall.push_back(Block(0, y));
		wall.push_back(Block(w - 1, y));
	}
	for (int x = 1; x < w - 1; x++) {
		wall.push_back(Block(x, 0));
		wall.push_back(Block(0, h - 1));
	}
}

Map::Map( size_t w , size_t h ) : width_(w), height_(h) {
	MapStuff::createWallAtConstruct(w, h, wall_); // fill the walls
	cookies_.reserve(4); // could be as much as we want
}

Map::~Map() {}

size_t	Map::getWidth() const {
	return width_;
}

size_t	Map::getHeight() const {
	return height_;	
}

std::vector< Block >&	Map::getCookies() {
	return cookies_;	
}

const std::vector< Block >&	Map::getWall() const {
	return wall_;
}
