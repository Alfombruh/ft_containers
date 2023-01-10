NAME = ft_containers
CC = c++
CFLAGS = -fsanitize=address -g3 #-Werror -Wall -Wextra
FILES = main

SRCS = $(addsuffix .cpp,$(FILES))
OBJS = $(addsuffix .o,$(FILES))

INCLUDES = srcs/

all: $(NAME)

.cpp.o: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $(SRCS) -o $@

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re