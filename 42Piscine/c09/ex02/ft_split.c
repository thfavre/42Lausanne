/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:36:31 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/22 10:39:38 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strndup(const char *s, int n)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	is_char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_number(char *str, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (str[++i])
		if (!is_char_in_str(sep, str[i])
			&& (i == 0 || is_char_in_str(sep, str[i - 1])))
			count++;
	return (count);
}

int	word_len(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !is_char_in_str(sep, str[i]))
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**res;

	j = 0;
	i = 0;
	res = malloc(sizeof(res) * (word_number(str, charset) + 1));
	while (str[i])
	{
		if (!is_char_in_str(charset, str[i])
			&& (i == 0 || is_char_in_str(charset, str[i - 1])))
		{
			res[j] = ft_strndup(str + i, word_len(str + i, charset));
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
/*
int main(int a, char **b) 
{
	(void)a;
	char **l = ft_split(b[1], b[2]);
	int i = 0 ;
	while (l[i])
		printf("->%s|\n", l[i++]);
}*/
