/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:36:42 by ade-beta          #+#    #+#             */
/*   Updated: 2022/04/12 16:11:29 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	clear(char *str, int *i, int pid, int *j)
{
	ft_printf("%s", str);
	kill(pid, SIGUSR2);
	*i = 0;
	*j = 0;
	free(str);
}

void	atend()
{

}

void	atfull()
{

}

void	handle(int sig, siginfo_t *pid, void *del)
{
	static char	*buff;
	static int	i = 0;
	static int	j = 0;
	static int	count = 0;

	if (!j)
	{
		buff = ft_calloc(257, 1);
		j = 1;
	}
	if (!buff)
		exit(0);
	buff[i] <<= 1;
	del += 0;
	count++;
	if (sig == SIGUSR1)
		buff[i] += 1;
	if (count == 8)
	{
		count = 0;
		if (!buff[i])
		{
			clear(&buff[0], &i, pid->si_pid, &j);
			return ;
		}
		if (i != 0 && i % 256 == 0)
			buff = ft_strjoin(buff);
		i++;
	}
	kill(pid->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID = %d\n", (int)getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		continue ;
}
