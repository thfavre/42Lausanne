/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 05:15:21 by marvin            #+#    #+#             */
/*   Updated: 2022/10/29 05:15:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int	char_in_set(char c, char const *set)
{
	if (ft_strchr(set, c) != NULL)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	// j = ft_strlen(s1);
	// while (ft_strchr(set, s1[j]))
	// 	i++;
	str = malloc(sizeof(*str) * (ft_strlen(s1) + 1 - i));
	ft_memcpy(str, s1, ft_strlcpy(s1) - i);
	printf("->%s<", str);
	return (str);
}


int main(){ft_strtrim("abcdef abcdef", "ab");}
