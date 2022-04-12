/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:37:00 by ade-beta          #+#    #+#             */
/*   Updated: 2022/04/12 15:34:54 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_check = 1;

void	handle(int sig)
{
	if (sig == SIGUSR1)
		g_check = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Message received.\n");
		exit(0);
	}
}

void	chopper(int pid, char c)
{
	unsigned char	mask;

	mask = 1 << 7;
	while (mask)
	{
		if (g_check)
		{
			g_check = 0;
			if (c & mask)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			mask >>= 1;
			usleep(2);
		}
	}
}

/*void	chopper(int pid, char c)
{
	unsigned char	mask;

	mask = 1 << 7;
	ft_printf("j = %d\n", *j);
	while (mask)
	{
		ft_printf("1\n");
		*j = 0;
		if (c & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		mask >>= 1;
	}
}*/

int	main(int argc, char **argv)
{
	int					i;

	i = -1;
	signal(SIGUSR1, &handle);
	signal(SIGUSR2, &handle);
	if (argc != 3 || kill(ft_atoi(argv[1]), 0))
		return (1);
	while (argv[2][++i])
		chopper(ft_atoi(argv[1]), argv[2][i]);
	i = -1;
	while (++i != 8)
		chopper(ft_atoi(argv[1]), 0);
	while (1)
		continue ;
}
