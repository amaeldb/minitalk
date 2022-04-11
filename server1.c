#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <strings.h>

void	ft_handle(int si)
{
	static char buf[256];
	static int	i;
	static int	j;

	buf[j] <<= 1;
	if (si == SIGUSR1)
//		write(1, "1\n", 2);
		buf[j] += 1;
//	if (si == SIGUSR2)
//		write(1, "0\n", 2);
	i++;
	if (i == 7)
	{
		if (!buf[j])
		{
			printf("%s\n", buf);
			write(1, "\nDONE\n", 6);
			j = 0;
			i = 0;
			bzero(buf, 256);
			return ;
		}
		//write(1, &buf[j], 1);
		j++;
		i = 0;
	}
	//printf("\nbuf = %s\n", buf);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = ft_handle;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Process ID: %d\n", (int)getpid());
	while (1)
	{
		//signal(SIGUSR1, &ft_handle);
		//signal(SIGUSR2, &ft_handle);
		continue;
	}
	return (0);
}
