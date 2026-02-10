/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:36:56 by ksener            #+#    #+#             */
/*   Updated: 2026/01/24 16:41:41 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	formalloc(long n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
	{
		n = -n;
		counter++;
	}
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	long int		m;

	m = n;
	str = malloc(formalloc(m) + 1);
	if (!str)
		return (NULL);
	i = formalloc(m);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		m = -m;
		str[0] = '-';
	}
	if (m == 0)
		str[0] = '0';
	while (m > 0)
	{
		str[i] = m % 10 + '0';
		m = m / 10;
		i--;
	}
	return (str);
}
