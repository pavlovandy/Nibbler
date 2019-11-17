/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:38:56 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/17 20:05:24 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_DOT_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_DOT_HPP

# include <cstddef>

template < class T = int >
struct Dot {
	T	x;
	T	y;

	Dot( T x = 0, T y = 0) : x(x), y(y) {}
	Dot( const Dot & d ) = default ;
	Dot&	operator=( const Dot & d ) = default;
	~Dot() = default;

	Dot<T>	operator+( const Dot<T> & rhs ) const {
		return (Dot<T>{x + rhs.x, y + rhs.y});
	}
	Dot<T>	operator-( const Dot<T> & rhs ) const {
		return (Dot<T>{x - rhs.x, y - rhs.y});
	}
	//to check collision
	bool	operator==( const Dot<T> & rhs ) const {
		return (rhs.x == x && rhs.y == y);
	}
	bool	operator!=( const Dot<T> & rhs ) const {
		return (!operator==(rhs));
	}
};

#endif