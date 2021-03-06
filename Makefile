SRCS	= 	ft_printf.c conv1.c conv2.c

OBJS	= ${SRCS:.c=.o}

HEAD	= ./minitalk.h

FLAGS	= -Wall -Wextra -Werror

NAME	= minitalk

.c.o:
		gcc ${FLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

printf:
		cd ./ft_printf && make

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

server:		ft_printf
			gcc ${FLAGS} server.c utils.c ./ft_printf/libftprintf.a -o server

clean:
		rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:		fclean
		make all
