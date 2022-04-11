SRCS	= 	ft_printf.c conv1.c conv2.c

OBJS	= ${SRCS:.c=.o}

HEAD	= ./ft_printf.h

FLAGS	= -Wall -Wextra -Werror

NAME	= minitalk

.c.o:
		gcc ${FLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

ft_printf:
		make -C ft_printf

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

server:		ft_printf
			gcc ${FLAGS} server.c utils.c ft_printf/libftprintf.a -o server

clean:
		rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:		fclean
		make all
