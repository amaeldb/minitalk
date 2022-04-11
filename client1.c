#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_handle(char *c, int pid)
{
	unsigned char	mask;
	int	i;

	i = -1;
	while (c[++i])
	{
		mask = 1 << 7;
		while (mask)
		{
			if (c[i] & mask)
			{
				kill(pid, SIGUSR1);
				printf("1");
			}
			else
			{
				kill(pid, SIGUSR2);
				printf("0");
			}
			mask >>= 1;
			usleep(1);
		}
	}
	i = 9;
	while (--i)
	{
		kill(pid, SIGUSR2);
		usleep(1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || kill(atoi(argv[1]), 0))	// ATTENTION ATOI
		return (1);
	ft_handle(argv[2], atoi(argv[1]));		// ATTENTION ATOI
}
