/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:22:10 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/10 14:45:45 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s == c)
		s++;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	*wordcpy(const char *src, int *cursor, char c)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	src += *cursor;
	dest = ft_calloc(wordlen(src, c) + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (*src == c)
	{
		src++;
		i++;
	}
	while (*src != c && *src)
	{
		dest[j] = *src++;
		i++;
		j++;
	}
	dest[j] = 0;
	*cursor += i;
	return (dest);
}

int	count_words(char const *s, char c)
{
	int	words;
	int	flagnw;

	flagnw = 0;
	words = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (flagnw)
			{
				words++;
				flagnw = 0;
			}
			s++;
		}
		else
		{
			flagnw = 1;
			s++;
		}
	}
	if (flagnw)
		words++;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		nbwords;
	int		i;
	int		cursor;

	nbwords = 0;
	i = 0;
	cursor = 0;
	nbwords = count_words(s, c);
	split = ft_calloc(nbwords + 1, sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (i < nbwords)
	{
		split[i] = wordcpy(s, &cursor, c);
		i++;
	}
	split[i] = NULL;
	return (split);
}
