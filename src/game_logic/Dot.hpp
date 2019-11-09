/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:38:56 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/09 16:17:27 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_DOT_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_DOT_HPP

# include <cstddef>

template < class T = size_t >
struct Dot {
	T	x;
	T	y;

	Dot( size_t x = 0, size_t y = 0);
	Dot( const Dot & ) = default ;
	Dot&	operator=( const Dot & ) = default;
	~Dot() = default;

	Dot<T>	operator+( const Dot<T> & ) const ;
	Dot<T>	operator-( const Dot<T> & ) const ;
};

#endif