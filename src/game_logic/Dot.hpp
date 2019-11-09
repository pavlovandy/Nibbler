/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:38:56 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/09 17:58:04 by Andrii Pavl      ###   ########.fr       */
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

	Dot<T>	operator+( const Dot<T> & rhs ) const {
		return (Dot(x + rhs.x, y + rhs.y));
	}
	Dot<T>	operator-( const Dot<T> & rhs ) const {
		return (Dot(x - rhs.x, y - rhs.y));
	}
};

#endif