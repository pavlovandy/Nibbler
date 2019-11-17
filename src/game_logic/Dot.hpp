/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:38:56 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/11 17:30:28 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_DOT_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_DOT_HPP

# include <cstddef>

template < class T = size_t >
struct Dot {
	T	x;
	T	y;

	Dot( T x = 0, T y = 0) : x(x), y(y) {}
	Dot( const Dot & d ) = default ;
	Dot&	operator=( const Dot & d ) = default;
	~Dot() = default;

	//only works if next operator is Dot<int>
	//added to make movement like : pos = pos + velocity;
	Dot<T>	operator+( const Dot<int> & rhs ) const {
		return (Dot(static_cast<int>(x) + rhs.x, static_cast<int>(y) + rhs.y));
	}
	Dot<T>	operator-( const Dot<int> & rhs ) const {
		return (Dot(static_cast<int>(x) - rhs.x, static_cast<int>(y) - rhs.y));
	}
	//to check collision
	bool	operator==( const Dot<T> & rhs ) const {
		return (rhs.x == x && rhs.y == y);
	}
	bool	operator!=( const Dot<T> & rhs ) const {
		return (!operator=(rhs));
	}
};

#endif