/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:01:37 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 15:49:13 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != 0)
		size++;
	return (size);
}

static	size_t	ft_nsize(int n)
{
	size_t	size;

	if (n < 0)
		size = 1;
	else
		size = 0;
	while (1)
	{
		n /= 10;
		size++;
		if (n == 0)
			break ;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*itoa;
	long	number;

	number = n;
	size = ft_nsize(n);
	itoa = ft_calloc(size + 1, sizeof(char));
	if (number < 0)
	{
		itoa[0] = '-';
		number *= -1;
	}
	itoa[size] = '\0';
	while (1)
	{
		itoa[size - 1] = (number % 10) + 48;
		number /= 10;
		size--;
		if (number == 0)
			break ;
	}
	return (itoa);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

void	ft_exit(void)
{
	write(2, "Fatal error\n", 12);
}
