/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphicLibrary.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:50:49 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/09 16:34:12 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HEADERS_GRAPHIC_IGRAPHICLIBRARY_HPP
# define NIBBLER_HEADERS_GRAPHIC_IGRAPHICLIBRARY_HPP

class Snake;
class Map;

class IGraphicLibrary {
public:
	virtual ~IGraphicLibrary() {}
	virtual	void	displaySnake( const Snake & ) = 0;
	virtual	void	displayMap( const Map & ) = 0;
};

#endif