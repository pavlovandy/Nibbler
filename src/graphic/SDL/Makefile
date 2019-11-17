NAME	:= libSDL.so

CC		:= clang++
CFLAGS	:= -shared -fPIC -lSDL2 #-Wall -Werror -Wextra

SRCS	:= SDL.cpp


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