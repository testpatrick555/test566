SRCS	= src/main.c src/tail_lib.c
HEAD	= includes/tail_lib.h
OBJS	= $(SRCS:.c=.o)
FLAGS	= -Wall -Wextra -Werror
CC		= gcc
NAME	= ft_tail
INCLUDES = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ $^

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean