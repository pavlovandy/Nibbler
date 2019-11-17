/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Block.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:48:27 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/11 15:43:17 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Block.hpp"

Block::Block( size_t x , size_t y ) : pos_(Dot(x, y)) {}

Block::Block( const Block & f ) : pos_(f.pos_) {}

Block&	Block::operator=( const Block & f ) {
	pos_ = f.pos_;
	return *this;
}

bool Block::collision( const Dot<> & d ) {
	if (pos_ == d)
		return (true);
	return (false);
}