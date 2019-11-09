/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:52:58 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/09 15:46:00 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_IENTITY_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_IENTITY_HPP

# include "Dot.hpp"

class IEntity {
	public:
		virtual void draw() = 0;
		virtual ~IEntity() {}
};

#endif