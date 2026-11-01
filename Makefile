
NAME    = mygit

CC      = gcc
CFLAGS  = -Wall -Wextra -g
LDFLAGS =
LDLIBS  =

SRC     = $(wildcard *.c)
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

%.o: %.c mygit.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
