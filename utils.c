/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:37:41 by ade-beta          #+#    #+#             */
/*   Updated: 2022/04/11 14:37:42 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	ret;

	i = 0;
	ret = 0;
	neg = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = (ret * 10) + (nptr[i] - '0');
		i++;
	}
	return (ret * neg);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = malloc(size * nmemb);
	if (!ret)
		return (NULL);
	ft_memset(ret, 0, 257);
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (s1[++i])
		ret[i] = (char)s1[i];
	i = -1;
	while (s2[++i])
		ret[ft_strlen(s1) + i] = (char)s2[i];
	ret[i + ft_strlen(s1)] = '\0';
	return (ret);
}
