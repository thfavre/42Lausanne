/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:57:53 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/09 18:15:59 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	isset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*trim_one_char(char const *s1, int start)
{
	char	*trimmed;

	trimmed = ft_calloc(2, sizeof(char));
	trimmed[0] = s1[start];
	trimmed[1] = 0;
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (s1[0] == 0)
		return (ft_strdup(""));
	if (!set)
	{
		trimmed = ft_strdup(s1);
		return (trimmed);
	}
	end = ft_strlen(s1) - 1;
	start = 0;
	while (isset(s1[start], set))
		++start;
	while (isset(s1[end], set))
		--end;
	if (start == end)
		trimmed = trim_one_char(s1, start);
	else
		trimmed = ft_substr(s1, start, end - start + 1);
	return (trimmed);
}
