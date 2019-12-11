/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:47:46 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/20 18:04:07 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

Snake::~Snake() {
	snake_parts_.clear();
}

void		Snake::move() {
	for (auto i = snake_parts_.rbegin() ; i != snake_parts_.rend() - 1; ++i ) {
		*i = *std::next(i, 1);
	}
	snake_parts_[0] = snake_parts_[0] + direction_;
}

Snake::Snake( Dot<> head, size_t start_lenght ) : direction_{-1, 0}, sprint_(false) {
	snake_parts_.reserve(MAX_SNAKE_LENGTH);
	for ( size_t i = 0; i < start_lenght; i++) {
		snake_parts_.push_back(head);
		head = head - direction_;
	}
}

void		Snake::growUp() {
	if (lenght() < MAX_SNAKE_LENGTH)
		snake_parts_.push_back(snake_parts_.back());
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

bool		Snake::selfCollision() const {
	auto head = snake_parts_.front();
	for ( auto i = snake_parts_.begin() + 1; i != snake_parts_.end(); i++ ) {
		if (*i == head)
			return true;
	}
	return false;
}

size_t			Snake::collision( const std::vector< Dot<> > & block ) const {
	for ( auto i = block.begin(); i != block.end(); i++ ) {
		if (*i == *snake_parts_.begin())
			return static_cast<size_t>(i - block.begin());
	}
	return block.size();
}