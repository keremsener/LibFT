/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:32:53 by ksener            #+#    #+#             */
/*   Updated: 2026/01/26 11:34:23 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int					i;
	const unsigned char	*str;
	unsigned char		c2;

	if (!s)
		return (NULL);
	str = (const unsigned char *)s;
	c2 = (unsigned char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (str[i] == c2)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
