/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Block.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:54:09 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/17 23:08:19 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_Block_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_Block_HPP

# include "Dot.hpp"

class Block {
public:
	Block( int x = 0, int y = 0 );
	Block( const Block & );
	Block&	operator=( const Block & );
	bool collision( const Dot<> & );
	~Block() = default ;

	const Dot<>&	getPos() const ;
	
private:
	Dot<>	pos_;
};

#endif