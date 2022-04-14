/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:38:02 by ade-beta          #+#    #+#             */
/*   Updated: 2022/04/11 14:38:59 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
void	*ft_memset(void *s, int c, size_t n);
int		ft_printf(const char *str, ...);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1);
size_t	ft_strlen(const char *s);

#endif
