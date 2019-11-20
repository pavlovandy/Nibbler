/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:53:22 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/20 22:10:28 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_GRAPHIC_SFML_HPP
# define NIBBLER_GRAPHIC_SFML_HPP

# include "../IGraphicLibrary.hpp"
# include <SFML/Graphics.hpp>

class SFML : public IGraphicLibrary {
public:
	SFML( int w, int h );
	~SFML();
	void	displaySnake( const Snake & ) override ;
	void	displayMap( const MapStuff::Map & ) override ;
	ControlEvents	getNextEventInQueue( ) override ;
	void	update() override ;
	void	delay( size_t ms ) override ;

	SFML( const SFML & ) = delete;
	SFML&	operator=( const SFML & ) = delete;

private:
	void	displayRect( int x, int y, sf::Color c, int w, int h );
	enum {	SQUARE_SIZE = 20 };
	sf::RenderWindow	win_;
	sf::Event	ev_;
};

#endif