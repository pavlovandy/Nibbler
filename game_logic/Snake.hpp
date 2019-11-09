/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:53:40 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/09 16:40:15 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_SNAKE_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_SNAKE_HPP

# include "IEntity.hpp"
# include "Dot.hpp"
# include <vector>

class Snake {
public:
	Snake( Dot<> head, size_t start_lenght = 4 );
	~Snake();

	void		move();

private:
	enum { MAX_SNAKE_LENGHT = 40 };
	void		checkCollision() const ;
	void		growUp();

	Snake( const Snake & ) = delete;
	Snake&	operator=( const Snake & ) = delete;
	
	Dot<int>		direction;
	std::vector< Dot<> >	snake_parts;
};

#endif