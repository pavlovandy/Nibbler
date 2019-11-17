/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:53:40 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/11 17:32:22 by anri             ###   ########.fr       */
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
	~Snake() = default ;

	void		move();
	const std::vector< Dot<> >&	getSnake() const ;
	void		changeDir( Dot<int> );
	Dot<int>	getDir() const ;
	size_t		lenght() const ;
	void		growUp();

private:
	enum { MAX_SNAKE_LENGHT = 40 };

	Snake( const Snake & ) = delete;
	Snake&	operator=( const Snake & ) = delete;
	
	Dot<int>		direction_;
	std::vector< Dot<> >	snake_parts_;
};

#endif