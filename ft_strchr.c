/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:19:08 by ksener            #+#    #+#             */
/*   Updated: 2026/01/29 09:57:41 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c2;

	str = (unsigned char *)s;
	c2 = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c2)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (c2 == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
