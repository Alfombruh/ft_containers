NAME = ft_containers
CC = c++
CFLAGS = -fsanitize=address -g3 #-Werror -Wall -Wextra
FILES = main/main

SRCS = $(addsuffix .cpp,$(FILES))
OBJS = $(addsuffix .o,$(FILES))

INCLUDES = srcs/

all: $(NAME)

.cpp.o: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $(SRCS) -o $@

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $@

vector: main/vectormain.cpp
	$(CC) $(CFLAGS) -I $(INCLUDES) -c main/vectormain.cpp -o main/vectormain.o 
	$(CC) $(CFLAGS) -I $(INCLUDES) main/vectormain.o -o ft_vector

test: main/test.cpp
	$(CC) $(CFLAGS) -I $(INCLUDES) -c main/test.cpp -o main/test.o 
	$(CC) $(CFLAGS) -I $(INCLUDES) main/test.o -o ft_test

reverseit: main/reverseitmain.cpp
	$(CC) $(CFLAGS) -I $(INCLUDES) -c main/reverseitmain.cpp -o main/reverseitmain.o 
	$(CC) $(CFLAGS) -I $(INCLUDES) main/reverseitmain.o -o ft_reverseit


clean:
	rm -rf $(OBJS)
	rm -rf main/vectormain.o main/test.o

fclean: clean
	rm -rf $(NAME)
	rm -rf ft_vector ft_test ft_reverseit

re: fclean all

.PHONY: all clean fclean re