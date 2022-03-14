#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_handle(char c, int pid)
{
	unsigned char	mask;

	mask = 1 << 7;
	while (mask)
	{
		if (c & mask)
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
		usleep(0.00001);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || kill(atoi(argv[1]), 0))
		return (1);
	ft_handle(argv[2][0], atoi(argv[1]));
}
