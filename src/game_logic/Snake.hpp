/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:53:40 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/20 23:25:14 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_SNAKE_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_SNAKE_HPP

# include "Dot.hpp"
# include <vector>
# include "Dot.hpp"

class Snake {
public:
	explicit Snake( Dot<> head, size_t start_lenght = 4 );
    Snake( const Snake & ) = delete;
    Snake&	operator=( const Snake & ) = delete;
	~Snake();

	void		move();
	const std::vector< Dot<> >&	getSnake() const ;
	void		changeDir( Dot<int> );
	Dot<int>	getDir() const ;
	size_t			lenght() const ;
	void		growUp();
	void		sprintOn();
	void		sprintOff();
	bool		getSprintStatus() const ;
	bool		selfCollision() const ;
	size_t		collision( const std::vector< Dot<> > & food ) const ;

private:
	enum { MAX_SNAKE_LENGTH = 40 };
	
	Dot<int>	direction_;
	std::vector< Dot<> >	snake_parts_;
	bool		sprint_;
};

#endif