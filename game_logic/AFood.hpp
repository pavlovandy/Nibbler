/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AFood.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:54:09 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/09 16:43:06 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_AFOOD_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_AFOOD_HPP

# include "IEntity.hpp"

class AFood : public IEntity {
public:
	AFood( size_t x = 0, size_t y = 0, size_t size = 1 );
	~AFood();
	
private:
	Dot<size_t>	pos_;
	size_t		size_;
};

#endif