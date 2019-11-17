/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:50:17 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/11 18:09:08 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game( size_t w, size_t h ) : glib_(nullptr) {
	snake_ = std::make_unique<Snake>(w / 2, h / 2);
	map_ = std::make_unique< MapStuff::Map >(w, h);
}

void		Game::start() {}

bool		Game::setEverythingUp() {}
