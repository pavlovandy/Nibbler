/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:54:09 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/11 15:50:54 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_Block_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_Block_HPP

# include "IEntity.hpp"

class Block : public IEntity {
public:
	Block( size_t x = 0, size_t y = 0 );
	Block( const Block & );
	Block&	operator=( const Block & );
	virtual bool collision( const Dot<> & ) override ;
	virtual ~Block() = default ;
	
private:
	Dot<size_t>	pos_;
};

#endif