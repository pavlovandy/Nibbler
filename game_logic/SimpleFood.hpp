/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleFood.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:53:24 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/09 16:43:59 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_SIMPLEFOOD_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_SIMPLEFOOD_HPP

# include "AFood.hpp"

class SimpleFood : public AFood {
public:
	SimpleFood( size_t x = 0, size_t y = 0);
	SimpleFood( const SimpleFood & );
	SimpleFood&	operator=( const SimpleFood & );
	~SimpleFood();
};

#endif