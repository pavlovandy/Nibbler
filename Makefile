# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 22:23:36 by anri              #+#    #+#              #
#    Updated: 2019/11/09 17:58:27 by Andrii Pavl      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++ -std=c++14

FLAGS = -Wall -Wextra -Wconversion -Werror

NAME = nibbler

SRC =	main.cpp \
		game_logic/AFood.cpp  \
		game_logic/Game.cpp game_logic/Map.cpp \
		game_logic/SimpleFood.cpp game_logic/Snake.cpp

HEAD =	other/terminal_colors.hpp \
		game_logic/AFood.hpp game_logic/Dot.hpp \
		game_logic/Game.hpp game_logic/IEntity.hpp \
		game_logic/Map.hpp game_logic/SimpleFood.hpp \
		game_logic/Snake.hpp

HEADERS = $(addprefix $(SRC_DIR), $(HEAD))

SRC_DIR = ./src/

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

UNAME_S := $(shell uname -s)

LINKS :=

INCLUDES :=

all: obj_dir $(NAME)
	echo "Compilated"

obj_dir:
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LINKS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all