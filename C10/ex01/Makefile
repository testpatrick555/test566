SRCS		= src/main.c
OBJ			= $(SRCS:.c=.o)
FLAGS		= -Wall -Wextra -Werror
CC			= gcc
NAME		= ft_cat

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
