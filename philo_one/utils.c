/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:52:42 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 13:11:12 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*p;

	p = (char *)malloc(nelem * elsize);
	if (!p)
		ft_exit();
	p = ft_memset(p, 0, nelem * elsize);
	return ((void *)p);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || \
	c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long int		sum;
	int				negative;
	int				count;

	sum = 0;
	negative = 1;
	count = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			negative = -1;
	while (ft_isdigit(*nptr))
	{
		sum *= 10;
		sum += *nptr++ - '0';
		if (negative == -1 && sum < 0)
			return (0);
		if (negative == 1 && sum < 0)
			return (-1);
		count++;
	}
	if (count == 0)
		return (-1);
	return (sum * negative);
}
