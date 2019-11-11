/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:54:09 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/11 14:49:56 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_FOOD_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_FOOD_HPP

# include "IEntity.hpp"

class Food : public IEntity {
public:
	Food( size_t x = 0, size_t y = 0, size_t size = 1 );
	~Food();
	
private:
	Dot<size_t>	pos_;
	size_t		size_;
};

#endif