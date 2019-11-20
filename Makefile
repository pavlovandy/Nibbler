# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anri <anri@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 22:23:36 by anri              #+#    #+#              #
#    Updated: 2019/11/20 21:33:50 by anri             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++ -std=c++14

FLAGS = -Wall -Wextra -Wconversion

NAME = nibbler

SRC_DIR = ./src/

SRC = main.cpp game_logic/Game.cpp game_logic/Map.cpp game_logic/Snake.cpp other/DyLibLoad.cpp

HEAD =	other/terminal_colors.hpp other/DyLibLoad.hpp \
		game_logic/Dot.hpp \
		game_logic/Game.hpp \
		game_logic/Map.hpp \
		game_logic/Snake.hpp \
		graphic/IGraphicLibrary.hpp

HEADERS = $(addprefix $(SRC_DIR), $(HEAD))

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

UNAME_S := $(shell uname -s)

LINKS := -ldl

INCLUDES := 

all: sdl sfml obj_dir $(NAME) # sfml opengl
	echo "Compilated"

obj_dir:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/game_logic
	mkdir -p $(OBJ_DIR)/graphic
	mkdir -p $(OBJ_DIR)/other

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LINKS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

sdl:
	make -C src/graphic/SDL

sfml:
	make -C src/graphic/SFML

opengl:
	make -C src/graphic/OpenGL

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -C src/graphic/SDL fclean
	make -C src/graphic/SFML fclean
#make -C src/graphic/OpenGL fclean

re: fclean all