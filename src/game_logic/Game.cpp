/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:50:17 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/09 18:50:33 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game( size_t w, size_t h ) : snake_( w / 2, h / 2), map_(w, h), glib_(nullptr) {}

Game::~Game() { delete glib_; glib_ = nullptr; }

void		Game::start() {}

bool		Game::setEverythingUp() {}
