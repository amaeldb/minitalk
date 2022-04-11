#include "minitalk.h"

void	handle(int sig)
{
	//ft_printf("\nhandle\n");
	if (sig == SIGUSR1)
	{
		ft_printf("Message received.\n");
		exit(0);
	}
	else if (sig == SIGUSR2)
		usleep(500);
}

void	chopper(int pid, char c)
{
    unsigned char	mask;

	mask = 1 << 7;
	while (mask)
	{
		if (c & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		mask >>= 1;
		usleep(2);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
    int					i;

	i = -1;
	sa.sa_handler = handle;
	sigaction(SIGUSR1, &sa, 0);
	if (argc != 3 || kill(ft_atoi(argv[1]), 0))
		return (1);
	while (argv[2][++i])
	{
		signal(SIGUSR2, &handle);
		chopper(ft_atoi(argv[1]), argv[2][i]);
		//if (!(i % 255) && i > 0)
		//	usleep(500);
	}
	i = -1;
	while (++i != 8)
	{
		kill(ft_atoi(argv[1]), SIGUSR2);
		usleep(2);
	}
	while (1)
		continue;
}