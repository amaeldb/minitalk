/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:36:42 by ade-beta          #+#    #+#             */
/*   Updated: 2022/04/21 14:03:46 by ade-beta         ###   ########.fr       */
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

int	atend(char *buff, int *i, int pid, int *j)
{
	if (!buff[*i])
	{
		clear(&buff[0], i, pid, j);
		return (0);
	}
	if (*i != 0 && *i % 255 == 0)
	{
		buff = ft_strjoin(buff);
	}
	*i += 1;
	return (0);
}

char	*setup(int *j)
{
	char	*buff;

	*j = 1;
	buff = ft_calloc(257, 1);
	if (!buff)
		exit(0);
	return (buff);
}

void	handle(int sig, siginfo_t *pid, void *del)
{
	static char	*buff;
	static int	i = 0;
	static int	j = 0;
	static int	count = 0;

	del += 0;
	if (!j)
		buff = setup(&j);
	buff[i] <<= 1;
	if (sig == SIGUSR1)
		buff[i] += 1;
	if (++count == 8)
	{
		count = 0;
		if (!buff[i])
		{
			clear(&buff[0], &i, pid->si_pid, &j);
			return ;
		}
		if (i != 0 && i % 255 == 0)
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
