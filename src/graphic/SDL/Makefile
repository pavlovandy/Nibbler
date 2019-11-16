NAME	:= libSDL.so

CC		:= clang++
CFLAGS	:= -shared -fPIC -lSDL2 -Wall -Werror -Wextra

SRCS	:= SDLGraph.cpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $@ $^ -I ~/.brew/include -L ~/.brew/lib

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all