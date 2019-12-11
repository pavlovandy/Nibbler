/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:36:18 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/20 23:34:37 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SFML.hpp"

extern "C" {
	IGraphicLibrary*	allocator( int w, int h) {
		return new SFML(w, h);
	}

	void				deallocator( IGraphicLibrary* glib ) {
		delete glib;
	}
}

SFML::SFML( int w, int h ) {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	auto desktop = sf::VideoMode::getDesktopMode();
    auto xCenter = desktop.width / 2 - w * SQUARE_SIZE / 2;
    auto yCenter = desktop.height / 2 - h * SQUARE_SIZE / 2;
	win_.create(sf::VideoMode(w * SQUARE_SIZE, h * SQUARE_SIZE), "Nibbler SFML", sf::Style::Default, settings);
	win_.setMouseCursorVisible(false);
	win_.setPosition(sf::Vector2i(xCenter, yCenter));
    if (!score_font_.loadFromFile("resorces/fonts/SourceSansPro-Black.otf"))
        throw std::runtime_error("Couldn't load score font");
}

SFML::~SFML() { win_.close(); }

void	SFML::displayRect( int x, int y, sf::Color c, int w, int h ) {
	sf::RectangleShape rect(sf::Vector2f(w, h));
	rect.setPosition(x, y);
	rect.setFillColor(c);
	win_.draw(rect);
}

void	SFML::displaySnake( const Snake & snake ) {
	std::vector< Dot<> >::const_iterator part = snake.getSnake().begin();

	sf::ConvexShape head;
	head.setPointCount(8);
	head.setPoint(0, sf::Vector2f(0, SQUARE_SIZE));
	head.setPoint(1, sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
	head.setPoint(2, sf::Vector2f(SQUARE_SIZE * 0.95, SQUARE_SIZE * 0.4));
	head.setPoint(3, sf::Vector2f(SQUARE_SIZE * 0.7, SQUARE_SIZE * 0.2));
	head.setPoint(4, sf::Vector2f(SQUARE_SIZE * 0.53, 0.1));
	head.setPoint(5, sf::Vector2f(SQUARE_SIZE * 0.47, 0.1));
	head.setPoint(6, sf::Vector2f(SQUARE_SIZE * 0.3, SQUARE_SIZE * 0.2));
	head.setPoint(7, sf::Vector2f(0.05, SQUARE_SIZE * 0.4));
	head.setPosition(part->x * SQUARE_SIZE, part->y * SQUARE_SIZE);
	if (snake.getDir().x > 0)
	{
		head.rotate(90);
		head.move(SQUARE_SIZE, 0);
	}
	else if (snake.getDir().y > 0)
	{
		head.rotate(180);
		head.move(SQUARE_SIZE, SQUARE_SIZE);
	}
	else if (snake.getDir().x < 0)
	{
		head.rotate(270);
		head.move(0, SQUARE_SIZE);
	}
	head.setFillColor(sf::Color::Green);
	win_.draw(head);
	

	
	//displayRect(part->x * SQUARE_SIZE, part->y * SQUARE_SIZE, , SQUARE_SIZE, SQUARE_SIZE);
	part++;
	for ( ; part != snake.getSnake().end(); part++) {
		displayRect(part->x * SQUARE_SIZE, part->y * SQUARE_SIZE, sf::Color::Green, SQUARE_SIZE, SQUARE_SIZE);
	}
}

void	SFML::displayMap( const MapStuff::Map & map ) {
	displayRect(0, 0, sf::Color::Black, map.getWidth() * SQUARE_SIZE, map.getHeight() * SQUARE_SIZE);
	
	for (auto & food : map.getCookies()) {
		sf::CircleShape shape(SQUARE_SIZE / 2);
		shape.setPosition(food.x * SQUARE_SIZE, food.y * SQUARE_SIZE);
		shape.setFillColor(sf::Color::Yellow);
		win_.draw(shape);
	}
	for (auto & wall : map.getWall()) {
		displayRect(wall.x * SQUARE_SIZE, wall.y * SQUARE_SIZE, sf::Color::Blue, SQUARE_SIZE, SQUARE_SIZE);
	}
}

ControlEvents	SFML::getNextEventInQueue( ) {
	if (win_.pollEvent(ev_)) {
		switch (ev_.type)
		{
			case sf::Event::Closed:
				return Quit;
			break;
			case sf::Event::KeyPressed:
				if (ev_.key.code == sf::Keyboard::Escape) return Quit;
				else if (ev_.key.code == sf::Keyboard::Num1) return Num1;
				else if (ev_.key.code == sf::Keyboard::Num2) return Num2;
				else if (ev_.key.code == sf::Keyboard::Num3) return Num3;
				else if (ev_.key.code == sf::Keyboard::Space) return StartSprint;
				else if (ev_.key.code == sf::Keyboard::W) return Up;
				else if (ev_.key.code == sf::Keyboard::S) return Down;
				else if (ev_.key.code == sf::Keyboard::A) return Left;
				else if (ev_.key.code == sf::Keyboard::D) return Right;
				else return UnTrackedEvent;
			break;
			case sf::Event::KeyReleased:
				if (ev_.key.code == sf::Keyboard::Space) return StopSprint;
				else return UnTrackedEvent;
			break;
			default: return UnTrackedEvent; break;
		}
	}
	else
		return NoEvent;
}

void	SFML::update() {
	
	win_.display();
	win_.clear();
}

void	SFML::delay( int64_t ms ) {
	sf::sleep(sf::milliseconds(ms));
}

void    SFML::displayScore( int x, int y, std::string text ) {
    static_cast<void>(x);
    static_cast<void>(y);
    sf::Text    txt;
    txt.setFont(score_font_);
    txt.setString(text);
    txt.setCharacterSize(80);
    txt.setFillColor(sf::Color::Red);
    txt.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
    txt.setOutlineColor(sf::Color::Yellow);
    txt.setOutlineThickness(-2);
    txt.setPosition((x - 0.5) * SQUARE_SIZE, (y - 0.4) * SQUARE_SIZE);
    win_.draw(txt);
}
