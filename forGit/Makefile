FLAGS = -Wall -Wextra -Werror

all:	client server

printf:
	@make -C ft_printf

client:	client.o utils.o printf
	@gcc ${FLAGS} client.o utils.o ft_printf/libftprintf.a -o client

server:	server.o utils.o printf
	@gcc ${FLAGS} server.o utils.o ft_printf/libftprintf.a -o server

clean:
	@rm -rf *.o
	@make clean -C ft_printf

fclean: clean
	@rm -rf client server
	@make fclean -C ft_printf
