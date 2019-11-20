CC		:= clang++
CFLAGS	:= -shared -fPIC -lSDL2 -Wall -Werror -Wextra

SRCS	:= SDL.cpp ../../game_logic/Snake.cpp ../../game_logic/Map.cpp

UNAME_S := $(shell uname -s)
SDL_PACKEAGES = 

NAME	:=

ifeq ($(UNAME_S),Darwin)
	NAME	+= ../../libSDL.dylib
	SDL_PACKEAGES += -I ~/.brew/include -L ~/.brew/lib
else 
	NAME	+= ../../libSDL.so
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $@ $^ $(SDL_PACKEAGES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all