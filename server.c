#include "minitalk.h"

void	clear(char *str, int *i, int *count)
{
	ft_printf("%s", str);
	//str = ft_memset(str, 0, 257);
	*i = 0;
	*count = 0;
}

void	handle(int sig, siginfo_t *pid, void *del)
{
	static char	buff[257];
	static int	i;
	static int	count;

	buff[i] <<= 1;
	buff[256] = 0;
	del = 0;
	count++;
	if (sig == SIGUSR1)
		buff[i] += 1;
	if (count == 8)
	{
		if (!buff[i])
		{
			clear(&buff[0], &i, &count);
			kill(pid->si_pid, SIGUSR1);
			return ;
		}
		if (i == 255)
		{
			kill(pid->si_pid, SIGUSR2);
			clear(&buff[0], &i, &count);
			return ;
		}
		i++;
		count = 0;
	}
}

int main(void)
{
	struct sigaction	sa;

	ft_printf("PID = %d\n", (int)getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		continue;
}