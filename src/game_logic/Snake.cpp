/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:47:46 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/11 17:29:03 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

// set last like a first at prev frame
// and just move first
// 'couse anything after first and last shouldnt be changed

void		Snake::move() {
	auto& last = snake_parts_.back();
	last = snake_parts_[0];
	snake_parts_[0] = snake_parts_[0] + direction_;
}



Snake::Snake( Dot<> head, size_t start_lenght = 4 ) : direction_{1, 0} {
	snake_parts_.reserve(MAX_SNAKE_LENGHT);
	for ( int i = 0; i < start_lenght; i++) {
		snake_parts_.push_back(head);
		head = head + direction_;
	}
}

void		Snake::growUp() {
	snake_parts_.push_back(snake_parts_.back()); // place like last element. At the next frame \
	this will moves before head and last one will holded.
}

const std::vector< Dot<> >&	Snake::getSnake() const  {
	return snake_parts_;
}

void		Snake::changeDir(Dot<int> new_dir) {
	direction_ = new_dir;
}

Dot<int>	Snake::getDir() const {
	return direction_;
}

size_t		Snake::lenght() const {
	return snake_parts_.size();
}
