/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:53:40 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/17 23:28:20 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_SNAKE_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_SNAKE_HPP

# include "Dot.hpp"
# include <vector>
# include "Block.hpp"

class Snake {
public:
	Snake( Dot<> head, size_t start_lenght = 20 );
	~Snake();

	void		move();
	const std::vector< Dot<> >&	getSnake() const ;
	void		changeDir( Dot<int> );
	Dot<int>	getDir() const ;
	int			lenght() const ;
	void		growUp();
	void		sprintOn();
	void		sprintOff();
	bool		getSprintStatus() const ;
	bool		selfColision() const ;
	bool		obstacleColision( const std::vector< Block > & wall ) const ;
	size_t		foodColison( const std::vector< Block > & food ) const ;

private:
	enum { MAX_SNAKE_LENGHT = 40 };

	Snake( const Snake & ) = delete;
	Snake&	operator=( const Snake & ) = delete;
	
	Dot<int>	direction_;
	std::vector< Dot<> >	snake_parts_;
	size_t		last_el_;
	bool		sprint_;
};

#endif