CC		:= clang++
CFLAGS	:= -shared -fPIC -lsfml-graphics -lsfml-window -lsfml-system -rpath -Wall -Werror -Wextra

SRCS	:= SFML.cpp ../../game_logic/Snake.cpp ../../game_logic/Map.cpp

UNAME_S := $(shell uname -s)

NAME := 

ifeq ($(UNAME_S),Darwin)
	NAME	+= ../../libSFML.dylib
	SFML_PACKEAGES += -I ~/.brew/include -L ~/.brew/lib
else
	NAME	+= ../../libSFML.so
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $@ $^ $(SFML_PACKEAGES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all