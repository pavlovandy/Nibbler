NAME	:= ../../libSDL.so

CC		:= clang++
CFLAGS	:= -shared -fPIC -lSDL2 -Wall -Werror -Wextra

SRCS	:= SDL.cpp ../../game_logic/Snake.cpp ../../game_logic/Map.cpp ../../game_logic/Block.cpp


UNAME_S := $(shell uname -s)
SDL_PACKEAGES = 

ifeq ($(UNAME_S),Darwin)
	SDL_PACKEAGES += -I ~/.brew/include -L ~/.brew/lib
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $@ $^ $(SDL_PACKEAGES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all