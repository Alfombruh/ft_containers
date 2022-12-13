NAME = ft_containers.a
CC = clang++
CFLAGS = -Werror -Wall -Wextra -fsanitize=address -g3
FILES = 

SRCS = $(addsuffix .cpp,$(FILES))
OBJS = $(addsuffix .o,$(FILES))

INCLUDES = 

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(OBJS) $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re