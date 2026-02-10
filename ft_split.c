/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:04:03 by ksener            #+#    #+#             */
/*   Updated: 2026/01/29 10:17:33 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	word_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	get_word(const char *str, char c)
{
	int	i;
	int	letters;

	letters = 0;
	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		letters++;
		i++;
	}
	return (letters);
}

static char	*write_word(const char **str, char c)
{
	int		i;
	char	*word;

	word = malloc(get_word((*str), c) + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while ((*str)[i] != c && (*str)[i] != '\0')
	{
		word[i] = (*str)[i];
		i++;
	}
	*str += i;
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		j;
	int		wordcount;

	if (!s)
		return (NULL);
	wordcount = word_count(s, c);
	j = 0;
	matrix = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	while (j < wordcount)
	{
		while (*s == c && *s != '\0')
			s++;
		matrix[j] = write_word(&s, c);
		if (!matrix[j++])
		{
			while (j > 0)
				free(matrix[--j]);
			return (free(matrix), NULL);
		}
	}
	matrix[j] = NULL;
	return (matrix);
}
