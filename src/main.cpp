/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:44:46 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/23 18:57:14 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "game_logic/Game.hpp"
#include "other/terminal_colors.hpp"
#include <string>

bool	get_numbers( int & a, int & b, char ** argv) {
	try
	{
		a = std::stoi(argv[1]);
		b = std::stoi(argv[2]);
		if (a < 15 || a > 100 || b < 15 || b > 60)
		{
			std::cout << RED << "Usage: " << COLOR_OFF << std::endl;
			return false;
		}
		return (true);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << RED << "We dont do that here" << COLOR_OFF << std::endl;
		return (false);
	}
}

int		main( int argc, char ** argv ) {
	if (argc == 3)
	{
		int w = 0;
		int h = 0;
		if (get_numbers(w, h, argv) == false)
			return (0);
		try
		{
			std::cout << system("pwd") << std::endl;
			Game	game(w, h, SDL_LIB_PATH, SFMLSOUND_LIB_PATH);
			game.startMenu();

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else {
		std::cout << RED << "Usage: " << COLOR_OFF << std::endl;
	}
	return (0);
}
