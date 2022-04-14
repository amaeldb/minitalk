SRCS	= 	ft_printf.c conv1.c conv2.c

OBJS	= ${SRCS:.c=.o}

HEAD	= ./ft_printf.h

FLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

.c.o:
	@gcc ${FLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	@ar rc ${NAME} ${OBJS}

clean:
	@rm -f ${OBJS} ${OBJSB}

fclean:	clean
	@rm -f ${NAME}

re:		fclean
		@make all
