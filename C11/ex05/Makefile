NAME	= do-op
SRC		= src/functions.c src/utility.c src/main.c
OBJS	= $(SRC:.c=.o)
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY:	all clean fclean