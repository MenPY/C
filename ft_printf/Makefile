SRCS		= 	$(shell find "./src" -name "*.c") ft_printf.c
OBJS		= 	${SRCS:.c=.o}
NAME		= 	libftprintf.a
CC			= 	gcc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror
AR			= 	ar csr
.c.o :
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) :		${OBJS}
				${AR} ${NAME} ${OBJS}

all : 			${NAME}

clean :
				${RM} ${OBJS} 

fclean : 		clean
				${RM} ${NAME}

re : 			fclean all

.PHONY: 		all clean fclean re .c.o
