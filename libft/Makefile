
NAME = libft.a

SRC = $(wildcard *.c)


OBJS = $(SRC:.c=.o)

HDRS = libft.h

all: $(NAME)

$(NAME):
		gcc -Wall -Werror -Wextra -c  $(HDRS) $(SRC)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		/bin/rm -f $(OBJS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all







