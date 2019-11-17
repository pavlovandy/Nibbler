/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:52:58 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/11 15:41:02 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GAME_LOGIC_IENTITY_HPP
# define NIBBLER_HEADERS_GAME_LOGIC_IENTITY_HPP

# include "Dot.hpp"

class IEntity {
	public:
		virtual bool collision( const Dot<> & d ) = 0;
		virtual ~IEntity() {}
};

#endif