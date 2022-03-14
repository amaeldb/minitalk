#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	ft_handle(int i)
{
	static char buf[256];

	
	if (i == SIGUSR1)
		printf("1\n");
	if (i == SIGUSR2)
		printf("0\n");
	return ;
}

int	main(void)
{
	printf("%d\n", (int)getpid());
	while (1)
	{
		signal(SIGUSR1, &ft_handle);
		signal(SIGUSR2, &ft_handle);
	}
	return (0);
}
