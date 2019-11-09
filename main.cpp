/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:44:46 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/09 17:44:48 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "game_logic/Game.hpp"
#include "other/terminal_colors.hpp"
#include <string>

bool	get_numbers( int & a, int & b, char ** argv) {
	try
	{
		int w = std::stol(argv[1]);
		int h = std::stol(argv[2]);
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

		Game	game(w, h);
		game.start();

	}
	else {
		std::cout << RED << "Usage: " << COLOR_OFF << std::endl;
	}
	return (0);
}
