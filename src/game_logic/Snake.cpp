/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:47:46 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/17 23:28:07 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

// set last like a first at prev frame
// and just move first
// 'couse anything after first and last shouldnt be changed

Snake::~Snake() {
	snake_parts_.clear();
}

void		Snake::move() {
	auto& last = snake_parts_[last_el_];
	last = snake_parts_[0];
	snake_parts_[0] = snake_parts_[0] + direction_;
	last_el_--;
	if (last_el_ == 0)
		last_el_ = snake_parts_.size() - 1;	
}

#include <iostream>

Snake::Snake( Dot<> head, size_t start_lenght ) : direction_{-1, 0}, sprint_(false) {
	snake_parts_.reserve(MAX_SNAKE_LENGHT);
	for ( size_t i = 0; i < start_lenght; i++) {
		snake_parts_.push_back(head);
		head = head - direction_;
	}
	last_el_ = snake_parts_.size() - 1;
}

void		Snake::growUp() {
	snake_parts_.push_back(snake_parts_.back()); // place like last element. At the next frame 
	//this will moves before head and last one will holded.
}

const std::vector< Dot<> >&	Snake::getSnake() const  {
	return snake_parts_;
}

void		Snake::changeDir(Dot<int> new_dir) {
	if ((direction_ + new_dir) != Dot<int>{0, 0})
		direction_ = new_dir;
}

Dot<int>	Snake::getDir() const {
	return direction_;
}

int			Snake::lenght() const {
	return static_cast<int>(snake_parts_.size());
}

void		Snake::sprintOn() {
	sprint_ = true;
}
void		Snake::sprintOff() {
	sprint_ = false;
}

bool		Snake::getSprintStatus() const {
	return sprint_;
}

bool		Snake::selfColision() const {
	Dot<> head = snake_parts_[0];
	for ( size_t i = 1; i != snake_parts_.size(); i++) {
		if (snake_parts_[i] == head) 
			return true;
	}
	return false;
}

bool		Snake::obstacleColision( const std::vector< Block > & wall ) const {
	for ( auto& part : wall) {
		if (part.getPos() == *snake_parts_.begin())
			return true;
	}
	return false;
}

size_t			Snake::foodColison( const std::vector< Block > & food ) const {
	
	for ( size_t i = 0; i != food.size(); i++ ) {
		if (food[i].getPos() == *snake_parts_.begin())
			return i;
	}
	return food.size();
}